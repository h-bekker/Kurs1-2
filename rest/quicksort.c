#include <stdio.h>

int a[100005];

void quick(int left, int right) {
	if (right-left<=1) 
		return;
	int mid=(left+right)/2;
	int pivot=a[mid];
	int l=left, r=right-1;
	while (l<=r) {
		while (a[l]<pivot)
			l++;
		while (a[r]>pivot)
			r--;
		if (l<=r) {
			int t=a[l];
			a[l]=a[r];
			a[r]=t;
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
		scanf("%d",&a[i]);
	quick(1,n+1);
	for (i=1; i<=n; i++)
		printf("%d ",a[i]);
	printf("\n");
	}
