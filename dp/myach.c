#include <stdio.h>

long long int dp[35];

int main() {
	int n,i;
	scanf("%d",&n);
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	for (i=4; i<=n; i++)
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	printf("%lld",dp[n]);
	printf("\n");
	}
