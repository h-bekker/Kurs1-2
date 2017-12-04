#include <stdio.h>

char a[105][105];
int used[105][105];
int di[]={1,-1,0,0};
int dj[]={0,0,1,-1};
int n;

int dfs(int i,int j) 
{
	int k,i1,j1;
	used[i][j]=1;
	for ( ; ; )
		for (k=0; k<4; k++) {
			i1=i+di[k];
			j1=j+dj[k];
			if (i1>0 && i1<=n && j1>0 && j1<=n) {
				if (used[i1][j1]==0) {
					if (a[i1][j1]=='#') {
						printf("%d %d\n",i,j);
						used[i1][j1]=1;
						}
					else 
						dfs(i1,j1);
					}
				}
			}
}

int main() 
{
	int m,i,j;
	scanf("%d\n%d\n",&n,&m);
	for (i=1; i<=n; i++)
	{
		for (j=1; j<=m; j++)
			scanf("%c",&a[i][j]);
		scanf("\n");
	}
	dfs(1,1);
	for (i=1; i<=n; i++)
	{
		for (j=1; j<=m; j++)
			printf("%c",a[i][j]);
		printf("\n");
	}
}
