#include <stdio.h>

int max(int x, int y) {
	if (x>y) 
		return x;
	return y;
	}

int a[105][105], d[105][105];

int main() {
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	for (i=1; i<=n; i++)
		for (j=1; j<=m; j++)
			scanf("%d",&a[i][j]);
	for (i=1; i<=n; i++)
		d[i][0]=0;
	for (i=1; i<=m; i++)
		d[0][i]=0;
	d[1][1]=a[1][1];
	for (i=1; i<=n; i++)
		for (j=1; j<=m; j++)
			if ((i!=1) || (j!=1))
				d[i][j]=max(d[i][j-1],d[i-1][j])+a[i][j];
	printf("%d\n",d[n][m]);
	}
