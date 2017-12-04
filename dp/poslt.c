#include <stdio.h>

int dp[105];

int main() {
	int n,i;
	scanf("%d",&n);
	dp[1]=2;
	dp[2]=4;
	dp[3]=7;
	for (i=3; i<n; i++)
		dp[i+1]=dp[i]+dp[i-1]+dp[i-2];
	printf("%d\n",dp[n]);
	} 
	
