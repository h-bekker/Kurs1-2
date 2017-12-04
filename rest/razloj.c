#include <stdio.h>

int main() {
	int n,i;
	scanf("%d",&n);
	for (i=2; i*i<=n; i++)
		while (n % i == 0) {
			n=n/i;
			printf("%d ",i);
			}
	if (n>1)
		printf("%d\n",n);
	else
		printf("\n");
	}
