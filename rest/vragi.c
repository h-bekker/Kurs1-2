#include <stdio.h>

char a[105][105];

int main() 
{
	int n,d,i,j;
	scanf("%d %d\n",&n,&d);
	for (i=1; i<=d; i++) 
	{
		for (j=1; j<=n; j++)
			scanf("%c",&a[i][j]);
		if (i!=d && j!=n)
			scanf("\n");
	}
	int ans=0, k=0;
	int t;
	for (i=1; i<=d; i++)
	{
		t=0;
		for (j=1; j<=n; j++)
			if (a[i][j]=='0')
			{ 
				k++;
				t=1;
				break;
			}
		if (t==0)
		{
			if (k>ans)
				ans=k;
			k=0;
		}
	}
	if (k>ans)
		ans=k;		
	printf("%d\n",ans);
}
