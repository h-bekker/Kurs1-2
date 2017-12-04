#include <stdio.h>

int main() {
	int k;
	FILE* f;
	if ((f=fopen("/home/bekker/arry.txt","w"))!=NULL) {
		while (scanf("%d",&k)==1)
			fprintf(f,"%d ",k);
		}
	else
		printf("Error\n");
	return 0;
	}
