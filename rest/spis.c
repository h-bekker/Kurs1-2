#include <stdio.h>

int a[105][105];

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
	int j;
	for (i=1; i<=n; i++)
	{
		for (j=1; j<=n; j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}
		
		
