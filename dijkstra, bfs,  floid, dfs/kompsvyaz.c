#include <stdio.h>

int a[100005][100005];
int used[100005];
int n;

void dfs(int v,int k)
{
	int t;
	used[v]=k;
	for (t=1; t<=n; t++)
		if (used[t]==0 && a[v][t]==1)
			dfs(t,k);
}

int main() 
{
	int m,i,v1,v2;
	scanf("%d %d",&n,&m);
	for (i=1; i<=m; i++)
	{
		scanf("%d %d",&v1,&v2);
		a[v1][v2]=1;
		a[v2][v1]=1;
	}
	int k=0;
	for (i=1; i<=n; i++)
		if (used[i]==0) 
		{
			k++;
			dfs(i,k);
		}
	printf("%d\n",k);
}
