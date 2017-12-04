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
	int n,k,t,s,i,j;
	scanf("%d",&n);
	for (i=1; i<=n; i++) {
		scanf("%d",&k);
		for (j=1; j<=k; j++)
			scanf("%d",&a[j]);
		quick(1,k+1);
		t=a[1]*a[k];
		s=1;
		for (j=2; j<=k/2; j++)
			if (a[j]*a[k-j+1]!=t) {
				s=0;
				break;
			}
		printf("%d\n",s);
		}
 	}
