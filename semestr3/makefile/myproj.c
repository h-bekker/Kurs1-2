#include <stdio.h>
#include "mylib.h"

int main(void) {
	double ans1,ans2,ans3,p,q;
	scanf("%lf%lf",&p,&q);
	ans1=twain(0,5,p,q);
	ans2=xord(0,5,p,q);
	ans3=kass(0,5,p,q);
	printf("%f %f %f\n",ans1,ans2,ans3);
	return 0;
	}
