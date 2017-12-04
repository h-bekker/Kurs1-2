#include <stdio.h>
int main() {
	int n,m,max,min,i,j,k;
	int kol=0;
	scanf("%d %d", &n, &m);
	int a[n][m];
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			scanf("%d", &a[i][j]);
	for (i=0; i<n; i++) 
		for (j=0; j<m; j++) {
			min=a[i][j];
			for (k=0; k<m; k++)
				if (a[i][k]<=min)
					min=a[i][k];
			max=a[i][j];
			for (k=0; k<n; k++)
				if (a[k][j]>=max)
					max=a[k][j];
			if (max==min)
				kol++;
			}
	printf("%d\n", kol);
	return 0;
	}
