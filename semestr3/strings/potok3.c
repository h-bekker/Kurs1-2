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
	int n,m,k,i;
	char* c;
	FILE* f;
	if ((f=fopen(argv[1],"r"))!=NULL) {
		fscanf(f,"%d",&n)==1;
		while (fscanf(f,"%d",&m)==1) 
			n=max(n,m);
		k=0;
		m=n;
		while (n!=0) {
			n=n/10;
			k++;
			}
		c=(char*)malloc(k+1*sizeof(char));
		sprintf(c,"%d",m);
		//for(i=k-1; i>=0; i--) {
			//n=m % 10;
			//m=m/10;
			//*(c+i)=n+'0';
			//}
		if ((f=fopen(c,"w"))!=NULL)
			fprintf(f,"%s","");
		else
			printf("No access\n");
		}
	else
		printf("Error\n");
	fclose(f);
	return 0;
	}
		
