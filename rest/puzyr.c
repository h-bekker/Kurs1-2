#include <stdio.h>

struct point {
	int x;
	int y;
	};

struct point a[105];

void puzyr(int n) {
int i,j,t,u;
for (i=1; i<=n-1; i++)
	for (j=1; j<=n-i; j++)
		if (((a[j].x)*(a[j].x)+(a[j].y)*(a[j].y))>((a[j+1].x)*(a[j+1].x)+(a[j+1].y)*(a[j+1].y))) {
			t=a[j].x;
			u=a[j].y;		
			a[j].x=a[j+1].x;
			a[j].y=a[j+1].y;
			a[j+1].x=t;
			a[j+1].y=u;
			}
return;
}

int main() {
	int n,k;
	scanf("%d",&n);
	for (k=1; k<=n; k++)
		scanf("%d %d",&a[k].x,&a[k].y);
	puzyr(n);
	for (k=1; k<=n; k++)
		printf("%d %d\n", a[k].x, a[k].y);
	}
