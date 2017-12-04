#include <stdio.h>
#include <math.h>

int koll(long long int n) {
	int i, s=0;
	for (i=1; i<=sqrt(n); i++)
		if (n % i == 0)
			s++;

	return s;
	}

int f(long long int n) {
	if (n==1)
		return 1;
	return koll(n)+f(n-1);
	}

int main(void) {
	long long int n;
	int ans;	
	scanf("%lld",&n);
	ans=f(n);
	if (ans % 2 == 0)
		printf("YES\n");
	else
		printf("NO\n");
	}
