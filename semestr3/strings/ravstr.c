#include <stdio.h>
#include <string.h>

int main(void) {
	char str[100],dst[100];
	if (scanf("%99s%99s",str,dst)==2) {
		if (strcmp(str,dst)==0)
			printf("Strings are equal\n");
		else
			printf("Strings aren't equal\n");
		}
	else
		printf("Error!\n");
	printf("%d\n",strcmp(str,dst));
	return 0;	
	} 
		
