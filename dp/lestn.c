#include <stdio.h>

int min(int x, int y) {
	if (x>y) 
		return y;
	return x;
}

int dp[105], a[105];

int main() {
	int n,i;
	scanf("%d",&n);
	for (i=1; i<=n; i++)
		scanf("%d",&a[i]);
	dp[1]=a[1];
	dp[2]=a[2];
	for (i=3; i<=n; i++)
		dp[i]=a[i]+min(dp[i-1],dp[i-2]);
	printf("%d",dp[n]);
	printf("\n");
	}
