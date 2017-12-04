#include <stdio.h>

int a[105][105];
int used[105];

void dfs(int v,int n)
{
	int t;
	used[v]=1;
	for (t=1; t<=n; t++)
		if (a[v][t]==1 && used[t]==0)
			dfs(t,n);
}	
	

int main() 
{
	int n,s,i,j;
	scanf("%d %d",&n,&s);
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++)
			scanf("%d",&a[i][j]);
	dfs(s,n);
	int k=0;
	for (i=1; i<=n; i++)
		k+=used[i];
	printf("%d\n",k);
}
