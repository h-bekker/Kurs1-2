#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/wait.h>
#include<arpa/inet.h>

#define BUF_SIZE 1024

char *fname;
char buf[BUF_SIZE];
char lens[BUF_SIZE]; //строка для хранения длины файла
int lenlen = 0; //длина строки lens

void inttoch(int a) //переводит a в строку lens
{
	int i = 0, j;
	char tmp[BUF_SIZE];
	while (a != 0) {
		tmp[i] = a % 10 + '0';
		a = a / 10;
		i++;
	}
	i--;
	for (j = 0; i >= 0; i--, j++) {
		lens[j] = tmp[i]; //переворачиваем строку
	}
	lenlen = j; //запомним длину строки
}
void readfname(void) //читает имя файла
{
	int i = 0; //счетчик строки 
	int j = 5;
	char c = '0';
	if ((fname = (char *)calloc(1, sizeof(char))) == NULL) { //выделяем память для строки
		perror("calloc");
		_exit(1);
	}
	while (1) //пока не конец ввода
	{
		c = *(buf + j);
		if (c != ' ') {
			*(fname + i) = c; //формируем строку
			if ((fname = (char *)realloc(fname, (i + 1)*sizeof(char))) == NULL) { //выделяем память для след. буквы
				perror("realloc");
				_exit(1);
			}
			i++;
			j++;
		}
		else {
			//printf("the name of file is: %s\n", fname);
			return;
		}
	}
}
int main(int argc, char const *argv[])
{
	int port, ls, len, as, pid;
	char msg[BUF_SIZE];
	struct sockaddr_in addr;
	if (argc != 2) {
		printf("Invalid parameters\n");
		_exit(1);
	}
	if (sscanf(argv[1], "%d", &port) < 0 || port <= 0 || port > 65535) { //читаем номер порта
		printf("Invalid port number: %s\n", argv[1]);
		_exit(1);
	}
	if ((ls = socket(AF_INET, SOCK_STREAM, 0)) < 0) { //создаем сокет
		perror("socket");
		_exit(1);
	}
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(ls, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
		perror("bind");
		_exit(1);
	}
	if (listen(ls, 5) < 0) {
		perror("listen");
		_exit(1);
	}
	while(1) {
		while (waitpid(-1, NULL, WNOHANG) > 0);
		len = sizeof(addr);
		if ((as = accept(ls, (struct sockaddr*) &addr, &len)) < 0) {
			perror("accept");
			_exit(1);
		}
		if ((pid = fork()) < 0) {
			perror("fork");
			_exit(1);
		}
		if (!pid) { //child
			close(ls);
			printf("%d: Connection from %s:%d accepted.\n", getpid(),
						inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
			if (read(as, &buf, sizeof(buf)+1) < 0) {
				perror("recv");
				_exit(1);
			} 
			readfname(); //читаем имя файла
			printf("Message recieved:\n%s\n", buf);
			/* отправляем ответ браузеру */
			write(as, "HTTP/1.1 200 OK\n", 16);
			FILE *f;
            if (!(f = fopen(fname, "rb"))) {
                perror("fopen");
                close(as);
                _exit(1);
            }
			printf("%s\n",fname);
            fseek(f, 0, SEEK_END);
            int fsize1 = (int) ftell(f);
            inttoch(fsize1); //переводим размер файла в строку lens
            rewind(f);
            int sended1 = 0;
            int readed1 = 0;
            //printf("len = %s\n", lens);
			write(as, "Content-length: ", 16);
			write(as, lens, lenlen); //пишем строку размера файла и ее длину
			write(as, "\n", 2);
			write(as, "Content-Type: image/jpeg\n\n", 26);
            do {
                readed1 = fread(msg, 1, BUF_SIZE, f);
                write(as, msg, (size_t) readed1);
                sended1 += readed1;
            } while (sended1 != fsize1);
            fclose(f);
            write(as, "\n", 2); //конец файла
			shutdown(as, 2);
			return 0;
		}
		close(as);
	}
	return 0;
}
