#include <stdio.h>

int main() {
	int n,m;
	scanf("%d %d",&n, &m);
	int A[n][m];
	int k,i,j,l;
	k=i=j=l=0;
	while (k<n*m) {
		A[i][j]=k;		
		k++;
		if ((l==0) && (j<m-1))
			j++;
		else
			if ((l==1) && (j>0))
				j--;
			else
				if (l==0) {
					i++;
					l=1;
					}
				else {
					i++;
					l=0;
					}
		}	
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++)
			printf("%3d ",A[i][j]);
		printf("\n");
		}
	return 0;
	}
