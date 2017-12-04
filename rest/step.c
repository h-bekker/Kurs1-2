#include <stdio.h>

int main() {
	long long n;
	int a,i,j;
	scanf("%d",&a);
	int b, k=1;
	int c=a;
	for (i=2; i*i<=a; i++) {
		b=a;
		while (a % i == 0)
			a=a/i;
		if (a!=b)
			k=k*i;
		}
	k=k*a;
	//printf("%d\n",k);
	long long l;
	int m=k, t=0;
	a=c;
	for (i=1; i<=100; i++) {
		l=1;
		for (j=1; j<=k; j++)
			l=l*k;
		//printf("%lld\n",l);
		if (l % a == 0) {			
			t=1;
			break;
			}
		if (t==1)
			break;
		else 
			k=k+m;
		//printf("%d\n",k);
		}
	printf("%d\n",k);
	}
	


