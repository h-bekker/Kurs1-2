#include <stdio.h>

int a[1005];

void puzyr(int n) {
int i,j,t;
for (i=1; i<=n-1; i++)
	for (j=1; j<=n-i; j++)
		if (a[j]<a[j+1]) {
			t=a[j];		
			a[j]=a[j+1];
			a[j+1]=t;
			}
return;
}

int main() {
	int n,k;
	int s=0;
	scanf("%d",&n);
	for (k=1; k<=n; k++)
		scanf("%d",&a[k]);
	puzyr(n);
	for (k=1; k<=n; k+=3) 
		s+=a[k]+a[k+1];
	printf("%d\n",s);
	}
