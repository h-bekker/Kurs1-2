#include <stdio.h>

int d[105][10005], a[105];

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
		d[i][0]=0;
	for (i=1; i<=m; i++)
		d[0][i]=101;
	d[0][0]=0;
	for (i=1; i<=n; i++)
		for (j=0; j<=m; j++) {
			d[i][j]=d[i-1][j];
			if ((j>=a[i]) && (d[i][j]-d[i-1][j-a[i]]>1))
				d[i][j]=d[i-1][j-a[i]]+1;
			} 
	if (d[n][m]==101)
		printf("0\n");
	else
		printf("%d\n",d[n][m]); 
	}
