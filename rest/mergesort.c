#include <stdio.h>

int arr[100005],a[100005],b[100005],c[100005];

void merge(int left, int right, int*arr) {
	if ((right-left)<=1)
		return;
	int mid=(left+right)/2;
	merge(left,mid,arr);
	merge(mid,right,arr);
	int l=left, r=mid, p=left;
	while ((l<mid) && (r<right)) {
		if (arr[l]<arr[r]) {
			b[p]=arr[l];
			l++;
			}
 		else {
			b[p]=arr[r];
			r++;
			}
		p++;
		}
	while (l<mid) {
		b[p]=arr[l];
		p++;
		l++;
		}
	while (r<right) {
		b[p]=arr[r];
		p++;
		r++;
		}
	for (p=left; p<right; p++) 
		arr[p]=b[p];
	}

int main() {
	int n,k,i;
	scanf("%d",&n);
	for (i=1; i<=n; i++)
		scanf("%d",&a[i]);
	merge(1,n+1,a);
	scanf("%d",&k);
	for (i=1; i<=k; i++)
		scanf("%d",&c[i]);
	merge(1,k+1,c);
	for (i=1; i<=n; i++)
		printf("%d ",a[i]);
	printf("\n");
	for (i=1; i<=k; i++)
		printf("%d ",c[i]);
	printf("\n");
	}
