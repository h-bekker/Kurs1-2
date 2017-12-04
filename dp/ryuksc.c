#include <stdio.h>

int d[105][10005], a[105], w[105];

int max(int x,int y) {
	if (x>=y)
		return x;
	return y;
	}

int main() {
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	for (i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for (i=1; i<=n; i++)
		scanf("%d",&w[i]);
	for (i=1; i<=n; i++)
		d[i][0]=0;
	for (i=1; i<=m; i++)
		d[0][i]=0;
	d[0][0]=0;
	for (i=1; i<=n; i++)
		for (j=0; j<=m; j++) {
			d[i][j]=d[i-1][j];
			if ((j>=a[i]) && (d[i][j]<d[i-1][j-a[i]]+w[i]))
				d[i][j]=d[i-1][j-a[i]]+w[i]; 
			} 
	int ans;	
	ans=d[n][1];
	for (j=2; j<=m; j++)
		if (ans<d[n][j])
			ans=d[n][j];
	printf("%d\n",d[n][m]); 
	}
