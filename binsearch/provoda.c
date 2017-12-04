#include <stdio.h>

int main() {
	int n,k,a[10002];
	scanf("%d %d", &n, &k);
	int i;
	for (i=1; i<=n; i++)
		scanf("%d",&a[i]);
	int l=0, r=1e7+1;
	int m,t;
	a[0]=99, a[n+1]=1e7+1;
	while (r-l>1) {
		t=0;
		m=(l+r)/2;
		for (i=1; i<=n; i++)
			t+=a[i]/m;
		if (t>=k) 
			l=m;
		else
			r=m;
		}
	if (l!=0)	
		printf("%d\n", l);
	else
		printf("0\n");	
	}
