#include <stdio.h>
#include <stdlib.h>

void erotosphen(int n, int* str) {
	int i,j;
	for (i=2; i*i<=n; i++)
		if (str[i]==0)
			for (j=i*i; j<=n; j+=i)
				if (str[j]==0)
					str[j]=1;
	}

int main(void) {
	int n,i;
	int* str=NULL;
	scanf("%d",&n);
	if (!(str=(int*) calloc (n+1,sizeof(int)))) {
		printf("Error\n");		
		return 0; 
		}
	str[n]='\0';
	erotosphen(n,str);
	for (i=4; i<=n; i++)
		if ((str[i]==0) && (str[i-2]==0))
			printf("%d %d\n",i-2, i);
	}
