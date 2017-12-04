#include <stdio.h>

int main() {
	int n,k,a[10003];
	scanf("%d %d", &n, &k);
	int i,j;
	for (i=1; i<=n; i++)
		scanf("%d",&a[i]);
	int l=1, r=1e9;
	int m,t,u;
	a[0]=-1e9;
	a[n+1]=1e9;
	while (r-l>1) {
		m=(l+r)/2;
		t=a[1];
		for (i=2; i<=k; i++) {
			j=1;
			while (j<=n) 
				if (a[j]<t+m)
					j++;
				else
					break;
			if (j>n) {
				u=0;
				break;
				}
			t=a[j];
			u=1;
			}
		if ((j==n+1) && (u==0))
			r=m;
		else 
			l=m;
		}	 
	printf("%d\n",l);
	}		
			
