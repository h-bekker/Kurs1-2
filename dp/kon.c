#include <stdio.h>

int d[20][20];

int count(int i,int j,int n,int m) {
	if ((i==0) && (j==0))
		return 1;
	if ((i<0) || (j<0) || (i>=n) || (j>=m))
		return 0;
	if (d[i][j]==-1)
		d[i][j]=count(i-1,j-2,n,m)+count(i+1,j-2,n,m)+count(i-2,j-1,n,m)+count(i-2,j+1,n,m);
	return d[i][j];
	}

int main() {
	int i,j,n,m,ans;
	scanf("%d %d",&n,&m);
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			d[i][j]=-1;
	d[0][0]=1;
	ans=count(n-1,m-1,n,m);
	printf("%d\n",ans);
	}
