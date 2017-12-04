#include <stdio.h>

int main() {
	int x;
	x=0;
	--x ? --x: ++x;
	printf("%d\n",x);
	return 0;
	}
