#include <stdio.h>
#include <string.h>

char wr[100];

int strlen1(char *str) {
	char *d=str;
	int s=0;
	while(*str++)
		s++;
	return s;
	}			

int main(void) {
	int ans;
	if (scanf("%99s",wr)==1) {
			ans=strlen1(wr);
			printf("%d\n",ans);
			}
	else
		printf("Error!\n"); 
	return 0;
	}
