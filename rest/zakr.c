#include <stdio.h>

struct zakr {
	int x;
	int y;
	};

struct zakr a[15005];

void quick(int left, int right) {
	if (right-left<=1) 
		return;
	int mid=(left+right)/2;
	int pivot=a[mid].x;
	int l=left, r=right-1;
	while (l<=r) {
		while (a[l].x<pivot)
			l++;
		while (a[r].x>pivot)
			r--;
		if (l<=r) {
			int t=a[l].x, s=a[l].y;
			a[l].x=a[r].x;
			a[l].y=a[r].y;
			a[r].x=t;
			a[r].y=s;
			l++;
			r--;
			}
		}
	quick(left,r+1);
	quick(l,right);
	}

int main() {
	int n,i;
	scanf("%d",&n);
	for (i=1; i<=n; i++)
		scanf("%d %d",&a[i].x,&a[i].y);
	quick(1,n+1);
	int sum=0, t=-1e9-1;
	for (i=1; i<n; i++)
		if (a[i].y>t) {
			if (a[i].y<=a[i+1].x)
				sum+=a[i].y-a[i].x;
			else
				if ((a[i].y>a[i+1].y) && (a[i].x<a[i+1].x)) {
					sum+=a[i].y-a[i].x;
					t=a[i].y;
				}
				else
					sum+=a[i+1].x-a[i].x;
		}	
	if ((n==1) || (a[n].y>t)) {
		if (t==-1e9-1)
			sum+=a[n].y-a[n].x;
		else
			sum+=a[n].y-t;
		}
	printf("%d\n",sum);
	}
