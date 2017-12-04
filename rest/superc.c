#include <stdio.h>

int main() {
	int a,b,i,j,k,t,p;
	scanf("%d %d",&a,&b);
	for (i=a; i<=b; i++) {
		p=0;
		for (j=2; j<=i/2; j++) {
			t=0;
			for (k=2; k*k<=j; k++) 
				if (j % k == 0) {
					t=1;
					break;
					}
			if (t==0) {
				for (k=2; k*k<=i-j; k++) 
					if ((i-j) % k == 0) {
					t=1;
					break;
					} 
				if (t==0) {
					p=1;
					break;
					}
				}
			}
		if (p==1)
			printf("%d\n",i);
			}
	}
