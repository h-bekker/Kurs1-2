#include <stdio.h>

int d[1005][1005], a[1005], b[1005];

int main() {
	int n,m,i,j;
	scanf("%d",&n);
	for (i=1; i<=n; i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for (i=1; i<=m; i++)
		scanf("%d",&b[i]);
	for (i=1; i<=n; i++)
		d[i][0]=0;
	for (i=1; i<=m; i++)
		d[0][i]=0;
	for (i=1; i<=n; i++)
		for (j=1; j<=m; j++) {
			d[i][j]=0;
			if (a[i]==b[j])
				d[i][j]=d[i-1][j-1]+1;
			if (d[i-1][j]>d[i][j]) 
				d[i][j]=d[i-1][j];
			if (d[i][j-1]>d[i][j])
				d[i][j]=d[i][j-1];
		}
	printf("%d\n",d[n][m]);
	}
	
