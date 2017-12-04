#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(char* s1, char *s2) {
	char* fs=s1;
	char* sc=s2;
	int n=strlen(s2), m=strlen(s1), k=0;
	if (!(fs=(char*) realloc(fs,(m+n)*sizeof(char)))) goto end;
	while (n>k) {
		fs[m]=sc[k];
		m++;
		k++;
		}
end:
	return fs;
	}

int main(void) {
	char* str;
	char* prs;
	char c;
	int n=10, pos=0;
	str=(char*)malloc(n*sizeof(char));
	prs=(char*)malloc(n*sizeof(char));
	if (!(str=(char*) calloc (n,sizeof(char)))) goto out_of_memory; 
	while ((scanf("%c",&c)==1) && (c!='\n')) {
		if (pos==n) {
			n+=10;
			if (!(str=(char*) realloc(str,n*sizeof(char)))) goto out_of_memory;
			}
		str[pos]=c;
		pos++;
		}
	n=10;
	pos=0;
	if (!(prs=(char*) calloc (n,sizeof(char)))) goto out_of_memory; 
	while ((scanf("%c",&c)==1) && (c!='\n')) {
		if (pos==n) {
			n+=10;
			if (!(prs=(char*) realloc(prs,n*sizeof(char)))) goto out_of_memory;
			}
		prs[pos]=c;
		pos++;
		}
	str=concat(str,prs);
	printf("%s\n",str);
out_of_memory:
	free(str);
	free(prs);
	return 0;
	}
