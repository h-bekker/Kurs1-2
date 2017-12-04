#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
	if (a>b) 
		return a;
	else
		return b;
	}

int main(int argc, char** argv) {
	int n=10, pos=0, k=0;
	char c;
	char* str;
	char* ans=NULL;
	FILE* f;
	if ((f=fopen(argv[1],"r"))!=NULL) {
		if (!(ans=(char*) calloc (n,sizeof(char)))) {
			printf("Error\n");		
			return 0; 
			}
		while ((fscanf(f,"%c",&c)==1) && (c!='\n')) {
				if (pos==n) {
					n+=10;
					if (!(ans=(char*) realloc(str,n*sizeof(char)))) {
						printf("Error\n");
						return 0;
						}
					}
				ans[pos]=c;
				pos++;
				}
		//printf("%d\n",strlen(ans));
		for (; ; ) {
			if (!(str=(char*) calloc (n,sizeof(char)))) {
			printf("Error\n");		
			return 0; 
			}
			pos=0;
			while ((fscanf(f,"%c",&c)==1) && (c!='\n')) {
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
			if (feof(stdin))
				break;
			printf("%d\n",strlen(str));
			if (strlen(str)>strlen(ans))
				ans=strcpy(ans,str);
			//if (feof(stdin))
				//break;
			free(str);
			k++;
			if (k==5)
				break;
			}
		printf("%s\n",ans);
		}
	else
		printf("Error\n");
	fclose(f);
	return 0;	
	}
