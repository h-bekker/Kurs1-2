#include <stdio.h>
#include <math.h>

int main() {
	double c;
	scanf("%lf", &c);
	double l=1.0, r=1e10+1, eps=1e-7;
	double m;
	while (r-l>eps) {
		m=(l+r)/2;
		if ((m*m+sqrt(m))>c)
			r=m;
		else
			l=m;
		}
	printf("%lf\n",l);
	}
