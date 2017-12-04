#include <stdio.h>
#include <math.h>

int main() {
	int a,b,c,d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	double m;
	double l=-abs(d)-1, r=abs(d)+1, eps=1e-9;
	while (r-l>eps) {
		m=(l+r)/2;
		if ((a*m*m*m+b*m*m+c*m+d)*(a*l*l*l+b*l*l+c*l+d)>0)
			l=m;
		else
			r=m;	
		}	
	printf("%lf\n",m);
	return 0;
	}
