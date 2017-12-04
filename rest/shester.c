#include <stdio.h>

int nom(int a, int b) {
	int i;
	if (a>b) {
		for (i=a; i<=a*b; i+=a)
			if (i % b == 0) 
				break;
		return i;
		}
	else 
		if (b>a) {
			for (i=b; i<=a*b; i+=b)
				if (i % a == 0)
					break;
			return i;
			}
		else 
			return a;
	}

int main() {
	int n,k;
	scanf("%d %d",&n,&k);
	printf("%d\n",nom(n,k));
	}
