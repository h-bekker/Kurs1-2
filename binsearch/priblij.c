#include <stdio.h>

int main() {
	int n,k,a[100003],b[100003],i;
	scanf("%d %d",&n,&k);	
	for (i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for (i=1; i<=k; i++)
		scanf("%d",&b[i]);
	int l,r;
	a[n+1]=a[n];
	a[0]=a[1];
	int m,p,q;
	for (i=1; i<=k; i++) {
		l=0;
		r=n+1;
		while (r-l>1) {
			m=(l+r)/2;
			if (a[m]>=b[i]) {
				r=m;
				p=a[m]-b[i];
				}
			else {
				l=m;
				q=b[i]-a[m];
				}			
			}
		if (p>=q)
			printf("%d\n",a[l]);
		else
			printf("%d\n",a[r]);
		}
	}
