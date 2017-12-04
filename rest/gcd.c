#include <stdio.h>

int a[100005];

int gcd(int a, int b) {
	if (b==0)
		return a;
	return gcd(b,a%b);
	}

int main() {
	int n,v,i;
	scanf("%d %d",&n,&v);
	for (i=1; i<=n; i++)
		scanf("%d",&a[i]);
	int m=a[1];
	if (n>1) {
		m=gcd(a[1],a[2]);
		if (n>2)
			for (i=3; i<=n; i++)
				m=gcd(m,a[i]);
		}
	if (v % m == 0)
		printf("YES\n");
	else
		printf("NO\n");
	}
		
