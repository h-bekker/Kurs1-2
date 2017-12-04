#include <stdio.h>

char a[15][15];
int used[15][15];
int di[]={1,-1,0,0};
int dj[]={0,0,1,-1};
int n;

int dfs(int i,int j) 
{
	int k,i1,j1;
	used[i][j]=1;
	int ans=1;
	for (k=0; k<4; k++)
	{
		i1=i+di[k];
		j1=j+dj[k];
		if (i1>0 && i1<=n && j1>0 && j1<=n)
			if (used[i1][j1]==0 && a[i1][j1]=='.')
				ans+=dfs(i1,j1);
	}
	return ans;
}

int main() 
{
	int i,j;
	scanf("%d\n",&n);
	for (i=1; i<=n; i++)
	{
		for (j=1; j<=n; j++)
			scanf("%c",&a[i][j]);
		scanf("\n");
	}
	int x,y;
	scanf("%d %d",&x,&y);
	printf("%d\n",dfs(x,y));
}
