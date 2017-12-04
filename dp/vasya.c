#include <stdio.h>

int min(int x, int y) {
	if (x>y) 
		return y;
	return x;
}

int dp[1005];

int main() {
	int n,i;
	scanf("%d",&n);
	dp[1]=1;
	dp[2]=2;
	for (i=3; i<=n; i++)
		dp[i]=(i % 10)+min(dp[i-1],dp[i-2]);
	printf("%d",dp[n]);
	printf("\n");	
	}
