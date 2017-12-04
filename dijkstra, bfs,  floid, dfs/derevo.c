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
	int n,m,i,j,v1,v2;
	scanf("%d %d",&n,&m);
	for (i=1; i<=m; i++) 
	{
		scanf("%d %d",&v1,&v2);
		a[v1][v2]=1;	
		a[v2][v1]=1;
	}		
	int s,k,t=1;
	while ((m!=n-1) && (t<=n))
	{
		s=0;
		for (i=1; i<=n; i++)
			if (a[t][i]==1)
			{
				a[t][i]=0;
				a[i][t]=0;
				if (dfs(t,n)!=n) 
				{
					a[t][i]=1;
					a[i][t]=1;
				}
				else 
				{
					m--;
					if (m==n-1)
						break;
				}
				for (j=1; j<=n; j++)
					used[j]=0;			
			}
		t++;
	}
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++)
			if (a[i][j]==1) 
			{
				printf("%d %d\n",i,j);
				a[i][j]=0;
				a[j][i]=0;
			}
}
