#include <stdio.h>
int main() {
	int n,k;
	scanf("%d %d", &n, &k);
	int A[250000],i;
	for (i=1; i<=n; ++i)
		scanf("%d", &A[i]);
	int Flag[250000];
	for (i=1; i<=k; ++i)
		Flag[i]=0;
	int l=1, r=0;
	int len=n-1;
	int lans=0, rans=0, kol=0;
	while (r<n) {
		while ((kol<k) && (r<n)) 
			{
			r++;
			Flag[A[r]]++;
			if (Flag[A[r]] == 1)
				kol++;
			}
		while ((kol==k) && (l<=n)) 
			{
			if (r-l<len)
				{
				len=r-l;
				lans=l;
				rans=r;
				}
			Flag[A[l]]--;
			if (Flag[A[l]] == 0)
				kol--;
			l++;
			}
		}	
	printf("%d %d\n", lans, rans);
	return 0;
	}
