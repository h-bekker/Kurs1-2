#include <stdio.h>

int min(int x, int y) {
	if (x>y) 
		return y;
	return x;
	}

int dp[1000002];

int main() {
	int n,i;
	scanf("%d",&n);
	dp[1]=0;
	dp[2]=1;
	dp[3]=1;
	for (i=4; i<=n; i++)
		if ((i % 2 == 0) && (i % 3 == 0)) 
			dp[i]=min(dp[i-1],min(dp[i/2],dp[i/3]))+1;
		else
			if (i % 2 == 0) 
				dp[i]=min(dp[i-1],dp[i/2])+1;
			else
				if (i % 3 == 0)
					dp[i]=min(dp[i-1],dp[i/3])+1;
				else
					dp[i]=dp[i-1]+1;	
	printf("%d\n",dp[n]);
	}
