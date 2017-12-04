#include <stdio.h>

int main() {
	int n,k,a[100002],b[100002],i;
	scanf("%d %d",&n,&k);	
	for (i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for (i=1; i<=k; i++)
		scanf("%d",&b[i]);
	int l,r;
	a[n+1]=1e9+1;
	int m;
	for (i=1; i<=k; i++) {
		l=1; r=n+1;	
		while (r-l>1) {
			m=(l+r)/2;
			if (a[m]>b[i])
				r=m;
			else
				l=m;		
			}
		if (a[l]==b[i])
			printf("YES\n");
		else
			printf("NO\n");
		}
	}
