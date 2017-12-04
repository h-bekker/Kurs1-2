#include <stdio.h>
#include <string.h>

int gcd(int a, int b);
int ggcd(int k, int t); 

int* str=NULL;

int main(void) {
	int i,ans,x=10;
	if (!(str=(int*) calloc (x,sizeof(int)))) {
		printf("Error\n");		
		return 0; 
		}
	for (i=0; i<x; i++) 
		scanf("%d",&str[i]);
	ans=ggcd(2, gcd(str[0],str[1]));
	printf("%d\n",ans);
	return 0;
	}

int gcd(int a, int b) {
	if (b==0)
		return a;
	return gcd(b,a%b);
	}

int ggcd(int k, int t) {
	if (k==10)
		return t;
	return ggcd(k+1,gcd(t,str[k]));
	} 

