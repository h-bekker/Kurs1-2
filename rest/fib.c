#include <stdio.h>

int a[3];

int fibb(int p,int q) {
	if (p<=q) {
		a[0]=a[1];
		a[1]=a[2];
		a[2]=a[1]+a[0];
		p++;
		fibb(p,q);
		}
	return a[2];
	}

int main(void) {
	int n;
	if (scanf("%d",&n)!=1)
		printf("Error!\n");
	else
		a[0]=a[1]=a[2]=1;
	printf("%d\n",fibb(3,n));
	return 0;
	}

