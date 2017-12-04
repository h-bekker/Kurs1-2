#include <stdio.h>

int dp[1005];

int main() {
	int n,i;
	scanf("%d",&n);
	dp[0]=1;
	dp[1]=1;
	for (i=1; i<n; i++)
		dp[i+1]=(dp[i]+dp[i-1]) % 10;
	printf("%d\n",dp[n]);
	}
