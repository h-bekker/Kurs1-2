#include <stdio.h>

int dp[105], a[105], b[105];

int main() {
	int n,s,i,j,k;
	scanf("%d",&n);
	for (i=1; i<=n; i++)
		scanf("%d",&a[i]);
	scanf("%d",&s);
	dp[0]=0;
	for (i=1; i<=s; i++) {
		k=1;
		dp[i]=s+1;
		for (j=1; j<=n; j++) 
			if (i>=a[j])
				if (dp[i]>dp[i-a[j]]+1) { 
					dp[i]=dp[i-a[j]]+1;
					b[k]=a[i];
					k++;
					
					}
		}
	if (dp[s]==s+1)
		printf("No solution\n");
 	else {
		for (i=1; i<=k; i++)
			printf("%d ",b[i]);
		printf("\n");
	     }		
	}
