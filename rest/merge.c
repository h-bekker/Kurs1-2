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
	arr[1]=a[1];
	b[1]=c[1];
	int p=1, q=1;
	for (i=2; i<=n; i++)
		if (a[i]!=a[i-1]) {
			p++;
			arr[p]=a[i];
		}
	for (i=2; i<=k; i++)
		if (c[i]!=c[i-1]) {
			q++;
			b[q]=c[i];
		}
	int t=1;	
	if (p==q) {
		for (i=1; i<=p; i++)
			if (arr[i]!=b[i]) {
				t=0;
				break;
			}
		}
	else
		t=0;
	if (t==1)
		printf("YES\n");
	else 
		printf("NO\n");
	}
