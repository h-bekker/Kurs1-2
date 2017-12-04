#include <stdio.h>

struct lasts {
	int val;
	int ind;
	};

struct lasts f(int* a, int n, int k) {
	int flag=0;
	struct lasts l;
	int i;
	for (i=0; i<n; i++)
		if ((a[i]<=k) && (a[i]>=-k)) {
			l.val=a[i];
			l.ind=i;
			flag=1;
			}
	if (flag==0) {
		printf("-1\n");
		exit(1);
		}
	return l;
	}

int main(void) {
	struct lasts ans;
	int* x;
	int n,k,i;
	scanf("%d%d",&n,&k);
	if (!(x=(int*) calloc (n,sizeof(int)))) {
			printf("Error\n");		
			return 0; 
			}
	for (i=0; i<n; i++)
		scanf("%d",&x[i]);
	ans=f(x,n,k);
	printf("%d %d\n",ans.val,ans.ind);
	}
