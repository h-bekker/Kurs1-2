#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char analiz(char* str, int* kol) {
	int* arr;
	char c;
	int count,i,k;
	if (!(arr=(int*) calloc (257,sizeof(int)))) {
		printf("Error\n");		
		return 0; 
		}
	k=strlen(str);
	for (i=0; i<k; i++)
		*(arr+(int)*(str+i))=*(arr+(int)*(str+i))+1;
	c=0;
	count=*(arr);
	for (i=1; i<256; i++)
		if (*(arr+i)>count) {
			count=*(arr+i);
			c=i;
			*kol=count;
			}
	return c;
	}

char* getlines(void) {
	char* str;
	char c;
	int n=10, pos=0;
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
	char c;
	int ans=0;
	str=getlines();
	c=analiz(str,&ans);
	printf("%c\n%d\n",c,ans);
	free(str);
	return 0;
	}
