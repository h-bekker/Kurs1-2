#include <stdio.h>

int max(int x, int y) {
	if (x>y) 
		return x;
	return y;
	}

int dp[105], a[105];

int main() {
	int n,i;
	scanf("%d",&n);
	for (i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for (i=5; i<=n; i++)
		dp[i]=max(dp[i-1],dp[i-5]+a[i]+a[i-1]+a[i-2]+a[i-3]+a[i-4]);
	printf("%d\n",dp[n]*10);
	}
