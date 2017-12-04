#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

volatile int flag=0;

void sigint_handler(int signo) {
	flag=1;
	}

int main(int argc, char** argv) {
	signal(SIGINT,sigint_handler);
	int n=0,m=0,i,k;
	FILE* f;
	if ((f=fopen(argv[1],"w"))!=NULL) {
		k=strlen(argv[2]);
		while (m<k) {
			n=n*10+argv[2][m]-'0';
			m++;
			}			
		for (i=0; i<n; i++) {
			fputs(argv[3],f);
			if (flag==1) {
				printf("%d\n",i);
				flag=0;
				}
			sleep(1);
			}
		fclose(f);
		}
	else
		printf("Error, few arguments\n");
	return 0;
	}
		
