#include <stdio.h>

int x[100005], y[100005];

int main() {
	int a,b,i,j;
	scanf("%d %d",&a,&b);
	for (i=2; i<=b; i++)
		x[i]=i;
	int k;
	for (i=2; i<=b; i++) {
		k=i*i;
		while (k<=b) {
			x[k]=0;
			k+=i;
			}
		}
	for (i=2; i<=b; i++)
		if (x[i]!=0)
			for (j=i; j<=b; j++)
				if ((x[i]!=0) && (x[j]!=0))
					y[i+j]=i+j;
	if (a<4)
		a=4;
	for (i=a; i<=b; i++)
		if (y[i]!=0)
			printf("%d\n",i);
	}
