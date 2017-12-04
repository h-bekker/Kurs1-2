#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strspn1(char* s1, char* s2) {
	char* p=NULL;
	char* q=NULL;
	q=s1;
	while (*(q)!='\0') {
		p=s2;
		while (*(p)!='\0')
			if (*(q)==*(p)) {
				return 1;
				}
			else
				p++;
		q++;
		}
	return -1;
	}

int main(int argc, char** argv) {
	int n=10,i,pos,k;	
	FILE* f;
	char **str, *arr1, *arr2;
	char c;
	if (!(str=(char**) calloc(4,sizeof(char*)))) {
		printf("Error, memory no access\n");
		exit(1);
		}
	if (!(str[0]=(char*) calloc(n,sizeof(char)))) {
		printf("Error, memory no access\n");
		exit(1);
		}
	if (!(str[1]=(char*) calloc(n,sizeof(char)))) {
		printf("Error, memory no access\n");
		exit(1);
		}
	if (argc<2) {
		printf("Error, few arguments\n");
		exit(1);
		}
	if ((f=fopen(argv[1],"r"))!=NULL) {
		for (i=0; i<2; i++) {
			pos=0;
			while ((fscanf(f,"%c",&c)==1) && (c!='\n')) {
				if (pos==n) {
					n+=10;
					if (!(str[i]=(char*) realloc(str,n*sizeof(char)))) {
						printf("Error\n");
						return 0;
						}
					}
				str[i][pos]=c;
				pos++;
				}
			str[i][pos]='\0';
			}
		}
	str[2]=NULL;
	k=strspn1(str[0],str[1]);
	printf("%d\n",k);
	printf("%s\n%s\n",str[0],str[1]);
	free(str[0]);
	free(str[1]);
	free(str);
	return 0;
	}	
