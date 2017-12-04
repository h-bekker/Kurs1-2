#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getlines(void) {
	char* str;
	char c;
	int n=10, pos=0;
	str=(char*)malloc(n*sizeof(char));
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

int main(void) {
	char* str;
	str=getlines();
	int n=strlen(str);
	while (n>=0) {
		printf("%c",*(str+n));
		n--;
		}
	printf("\n");
	free(str);
	return 0;
	}
