#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <sys/wait.h>
#include <arpa/inet.h>

enum {SIZE=2048}; 
char* word;
char** words = NULL;
char buffer [SIZE];
char lens[SIZE];
int len = 0;
int argnumb=1;

void trans(int a) //переводит a в строку lens
{
	int i = 0, j;
	char tmp[SIZE];
	while (a != 0) {
		tmp[i] = a % 10 + '0';
		a = a / 10;
		i++;
	}
	i--;
	for (j = 0; i >= 0; i--, j++) {
		lens[j] = tmp[i]; //переворачиваем строку
	}
	len = j; //запомним длину строки
}
 
int readb(int ind) {//читает то, что надо 
	int i = 0;
	int k = 0;
	char c = '0';
	if ((words = (char **)calloc(1, sizeof(char*))) == NULL) { //выделяем память для строк
		perror("calloc");
		_exit(1);
	}
	for (k=0; k<argnumb; k++) {
		i=0;
		if ((word = (char *)calloc(1, sizeof(char))) == NULL) { //выделяем память для строки
			perror("calloc");
			_exit(1);
			}
		while (1) {
			c = *(buffer + ind);
			if (c != ' ') {
				*(word + i) = c; 
				if ((word = (char *)realloc(word, (i + 1)*sizeof(char))) == NULL) {
					perror("realloc");
					_exit(1);
					}
				i++;
				ind++;
				}
			else {
				*(word + i) = '\0';
				if ((word = (char *)realloc(word, (i + 1)*sizeof(char))) == NULL) {
					perror("realloc");
					_exit(1);
					}
				words[k]=word;
				if ((words = (char **)realloc(words, (k + 2)*sizeof(char*))) == NULL) {
					perror("realloc");
					_exit(1);
					}
				break;
				}
			}
		}
	return ind;
	}
	
int main(int argc, char const *argv[]) {
	int lfd, n, port, afd, alen, sopt, pid, pid1, indf, mth;
	struct sockaddr_in baddr, aaddr;
	struct tm *loctime ;
	time_t t;
	char* meth;
	char fir[4]={'G','E','T','\0'};
	char sec[5]={'H','E','A','D','\0'};
	char msg[SIZE];
	FILE* f;
	if (argc != 2) {
		fprintf(stderr, "Too few parameters\n");
		exit(1);
		}
/* прочитаем номер порта */
	if (sscanf(argv[1], "%d%n", &port, &n) != 1 || argv[1][n] || port <= 0 || port > 65535) {
		fprintf(stderr, "Bad port number: %s\n", argv[2]);
		exit(1);
		}
/* создаём сокет */
	if ((lfd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(1);
		}
/* задаём режим сокета */
	sopt = 1;
	if (setsockopt(lfd,SOL_SOCKET,SO_REUSEADDR,&sopt,sizeof(sopt))< 0){
		perror("setsockopt");
		exit(1);
		}
/* задаём адрес сокета */
	baddr.sin_family = AF_INET;
	baddr.sin_port = htons(port);
	baddr.sin_addr.s_addr = INADDR_ANY;
/* привязываем сокет */
	if (bind(lfd, (struct sockaddr *) &baddr, sizeof(baddr)) < 0) {
		perror("bind");
		exit(1);
		}
/* включаем режим прослушивания */
	if (listen(lfd, 5) < 0) {
		perror("listen");
		exit(1);
		}
	while (1) {
	/* хороним <<зомби>> */
		while (waitpid(-1, NULL, WNOHANG) > 0);
	/* ожидаем подключения */
		alen = sizeof(aaddr);
		if ((afd = accept(lfd, (struct sockaddr*) &aaddr, &alen)) < 0) {
			perror("accept");
			exit(1);
			}
	/* запросы клиентов будем обслуживать в другом процессе */
		if ((pid = fork()) < 0) {
			perror("fork");
		} else if (!pid) {
			mth=0;
			close(lfd);
		/* печатаем информацию о подключении */
		//printf("%d: Connection from %s:%d accepted.\n", getpid(),
		//inet_ntoa(aaddr.sin_addr), ntohs(aaddr.sin_port));
		//printf("http/1.0 501 <Not Implemented>\n");			
			if (read(afd, &buffer, sizeof(buffer)+1)<0) {
				fprintf(stderr, "read error\n");
				write(afd, "HTTP/1.0 400 Bad request", 23);
				} 
			else {
				printf("Message:\n%s\n", buffer);
				indf=readb(0); //какой метод
				if ((meth = (char *)calloc(strlen(words[0])+1, sizeof(char))) == NULL) { //память для метода
					perror("calloc");
					_exit(1);
					}
				meth=strcpy(meth,words[0]);
				if ((strcmp(meth,fir)==0) || (strcmp(meth,sec)==0))
					mth=1;
				if (!mth) {
					write(afd, "HTTP/1.0 501 Not Implemented\0", 28);
					write(afd, "Allow: GET,HEAD\0", 15);
					close(afd);
					_exit(0);
					}
				int v=indf+2;
				while (buffer[v] != ' '){
					if ((buffer[v] =='?') || (buffer[v] =='&')){
						argnumb++;
						}
					v++;
					}
				indf=readb(indf+2); //читаем название файла или быть может cgi
				int cgi=0;
				//fflush(NULL);
				if (strncmp(words[0],"cgi-bin",7) == 0) {
					cgi=1;
					if ((pid1 = fork())<0) {
						perror("fork");
						exit(1);
					}
					if (!pid1) {
						if ((f=freopen("tmp.txt","w",stdout))==NULL){
							perror("freopen");
							_exit(1);
							}
						if ((execvp(words[0],words))<0){
							perror("execvp");
							_exit(1);
							}
						fclose(f);
						shutdown(afd,2);
						return 0;
						}
					wait(NULL);
					}
				if (cgi) {
					if (!(f = fopen("tmp.txt","rb"))) {
						perror("fopen");
						close(afd);
						_exit(1);
						}
					}
				else {
					if (!(f = fopen(word, "r"))) {
						write(afd, "HTTP/1.0 404 Not Found\0", 22);
						perror("fopen");
						close(afd);
						_exit(1);
						}
					}
				write(afd,"HTTP/1.0 200 OK\0", 15);
				t = time(0);
				loctime = localtime (&t);
				strftime (buffer , SIZE, "Date: %a, %d %b %Y %X GMT\0", loctime);
				write(afd,buffer, 35);
				write(afd,"Server: Model HTTP Server/0.1\0", 29);
				fseek(f, 0, SEEK_END);
	            int fsize = (int) ftell(f); //получение размера файла
				trans(fsize); //переводим размер файла в строку
				fseek(f, 0, SEEK_SET);
	            int tell = 0;
	            int send = 0;
				write(afd, "Content-length: ", 16);
				write(afd, lens, len); //пишем строку размера файла и ее длину
				write(afd, "\n", 2);
				write(afd, "Content-Type: image/jpeg\n\n", 26);
	            do {
	                send = fread(msg, 1, SIZE-1, f);
					msg[SIZE]='\0';
					printf("%s\n",msg);
	                write(afd, msg, (size_t) send);
	                tell += send;
	            } while (tell != fsize);
				fclose(f);
				write(afd, "\n", 2); //конец файла 
				shutdown(afd, 2);
				}
			close(afd);
			_exit(0);
			}
		close(afd);
		}
	return 0;
	}
