#include <stdio.h>

int a[105][105];
int used[105];

int dfs(int v,int n)
{
	int t;
	used[v]=1;
	int ans=1;
	for (t=1; t<=n; t++)
		if (a[v][t]==1 && used[t]==0)
			ans+=dfs(t,n);
	return ans;
}	

	
int main() 
{
	int n,m,i,v1,v2;
	scanf("%d %d",&n,&m);
	for (i=1; i<=m; i++) 
	{
		scanf("%d %d",&v1,&v2);
		a[v1][v2]=1;	
		a[v2][v1]=1;
	}
	printf("%d\n",dfs(1,n));
}
