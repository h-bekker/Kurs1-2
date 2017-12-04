#include <stdio.h>

int main() {
	int T;
	scanf("%d",&T);
	int i,j,k;
	int N;
	int A[1001];
	for (i=0; i<T; i++) {
		scanf("%d",&N);
		for (j=0; j<N; j++)
			scanf("%d",&A[j]);
		for (j=1; j<N; j++)
			if (A[j-1] != A[j]) {
				k=A[j];
				A[j]=A[j-1];
				A[j-1]=k;
				}
		for (j=0; j<N; j++)
			printf("%d ",A[j]);
		printf("\n"); 
		}
	return 0;
	} 
