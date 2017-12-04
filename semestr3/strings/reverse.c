#include <stdio.h>
#include <string.h>

void rev(char *wr, char *pr) {
	int i;	
	for (i=0; i<=strlen(wr); i++)
			pr[i]=wr[strlen(wr)-1-i];
	}

int main (void) {
	char str[100],dst[100];
	if (scanf("%99s", str)==1) {
		rev(str,dst);
		printf("%s\n",dst);
		}
	else
		printf("Error!\n");
	return 0;
	}
		
