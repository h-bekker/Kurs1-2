#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		for (; ; ) {
			n=10;
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
			str[pos]='\0';
			if (strlen(str)>strlen(ans)) {
				if (!(ans=(char*) realloc(ans,strlen(str)+1*sizeof(char)))) {
						printf("Error\n");
						return 0;
						}
				ans=strncpy(ans,str,strlen(str));
				ans[strlen(ans)]='\0';
				}
			//printf("%c\n",str[pos-1]);
			//printf("%d\n",strlen(str));
			if (feof(f))
				break;
			free(str);
			}
		printf("%s\n",ans);
		}
	else
		printf("Error\n");
	fclose(f);
	return 0;	
	}
