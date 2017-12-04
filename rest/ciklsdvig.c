#include <stdio.h>

int main() {
	int N;
	scanf("%d",&N);
	int A[N],i;
	for (i=0; i<N; i++)
		scanf("%d",&A[i]);
	int m=A[N-1];
	for (i=N-2; i>-1; i--)
		A[i+1]=A[i];
	A[0]=m;
	for (i=0; i<N; i++)
		printf("%d ",A[i]);
	printf("\n");
	return 0;
	}

