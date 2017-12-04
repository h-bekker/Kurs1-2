#include <stdio.h>

main() {
	int i;
	for (i=31; i<128; i++) { 
		printf("%4d-%c ",i,i);
		if ((i % 10)==0)
			printf("\n");
		}
	printf("\n");
}	
