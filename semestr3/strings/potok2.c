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
	int n,m,i;
	char* c;
	FILE* f;
	if ((f=fopen(argv[1],"r"))!=NULL) {
		fscanf(f,"%d",&n);
		while (fscanf(f,"%d",&m)==1) 
			n=max(n,m);
		c=(char*)malloc(strlen(argv[1])+1*sizeof(char));
		for (i=0; i<strlen(argv[1])-3; i++)
			*(c+i)=*(argv[1]+i);
		*(c+i)='m';
		*(c+i+1)='a';
		*(c+i+2)='x';		
		*(c+i+3)='\0';
		if ((f=fopen(c,"w"))!=NULL)
			fprintf(f,"%d\n",n);
		else
			printf("No access\n");
		}
	else
		printf("Error\n");
	fclose(f);
	return 0;
	}
		
