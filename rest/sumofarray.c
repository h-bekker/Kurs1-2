#include <stdio.h>
#include <stdlib.h>

int main() {
	int k,ans=0;
	FILE* f;
	if ((f=fopen("/home/bekker/arry.txt","r"))!=NULL) {
		while (fscanf(f,"%d",&k)==1)
			ans+=k;
		}
	else {
		printf("Error\n");
		exit(1);
		}
	printf("%d\n",ans);
	return 0;
	}
