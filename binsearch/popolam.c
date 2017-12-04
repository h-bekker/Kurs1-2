#include <stdio.h>
#include <math.h>

int main() {
	double a;
	scanf("%lf", &a);
	int n,i;
	scanf("%d", &n);
	double l,r,eps,m,k;
	l=0;
	r=a+1;
	eps=1e-6;
	while (r-l>eps) {
		m=(l+r)/2;
		k=1;
		for (i=0; i<n; i++)
			k=k*m;
		if (k>a)
			r=m;
		else 
			l=m;
		}		
	printf("%lf\n", m);
	return 0;
	}
