#include <stdio.h>
int main() {
    int i,j,k,n;
    scanf("%d", &n);
    int c;
    int a[2*n + 1][2*n + 1];
    c = (2*n+1)*(2*n+1)-1;
    a[n][n] = 0;
    for (k = 0; k <= n; ++k) {
        for (i = k; i < 2*n - k; ++i)
		a[i][2*n - k] = c--;
        for (i = k; i < 2*n - k; ++i)
		a[2*n - k][2*n - i] = c--;
        for (i = k; i < 2*n - k; ++i)
		a[2*n - i][k] = c--;
        for (i = k; i < 2*n - k; ++i)
		a[k][i] = c--;
    	}
    for (i = 0; i <= 2*n; ++i) {
        for (j = 0; j <= 2*n; ++j)
			printf("%4d", a[i][j]);
   	printf("\n");
	}
 }
