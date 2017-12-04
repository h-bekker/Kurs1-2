#include <stdio.h>

int main() {
	int n,m,a[100002],b[1000002],i;
	scanf("%d",&n);	
	for (i=1; i<=n; i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);	
	for (i=1; i<=m; i++)
		scanf("%d",&b[i]);
	int l,r;
	a[n+1]=1e9+1;
	a[0]=0;
	int k;
	for (i=1; i<=m; i++) {
		l=0;
		r=n;
		while (r-l>1) {
			k=(l+r)/2;
			if (a[k]>=b[i])
				r=k;
			else
				l=k;
			}
		if (a[r]==b[i])
			printf("%d ",r);
		else 
			printf("0 ");
		l=1; 
		r=n+1;	
		while (r-l>1) {
			k=(l+r)/2;
			if (a[k]>b[i])
				r=k;
			else
				l=k;
			}
		if (a[l]==b[i])
			printf("%d\n",l);
		else
			printf("0\n");		
		}
	}
