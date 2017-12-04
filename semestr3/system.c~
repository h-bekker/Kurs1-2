#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int system(char const* cmd) {
	int pid,status;
	if ((pid=fork())<0) {
		perror("fork");
		return 1;
		}
	else
		if (!pid) {
			execl("/bin/sh","/bin/sh","-c",cmd,NULL);
			perror("execl");
			_exit(1);
			}
	wait(&status);
	if (WIFSIGNALED(status))
		return WTERMSIG(status)+256; //расширение сигнала
	return WEXITSTATUS(status);
	}

char* getword(void) {
	int n=10, pos=0, k;
	char c;
	char* str;
	if (!(str=(char*) calloc (n,sizeof(char)))) {
			printf("Error\n");		
			return 0; 
			}
	while ((scanf("%c",&c)==1) && (c!='\n')) {
			if (pos==n) {
						n+=10;
						if (!(str=(char*) realloc(str,n*sizeof(char)))) {
							printf("Error\n");
							return 0;
							}
						}
			str[pos]=c;
			pos++;
			}
	return str;
	}

int main() {
	int n=10, pos=0, k;
	char c;
	char* str;
	while (!feof(stdin)) {
		str=getword();
		printf("%d\n",system(str));		
		}
	}
