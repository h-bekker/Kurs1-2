#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	//printf("argv[0] = %s\n", argv[0]);
	sscanf(argv[1], "%d", &a);
	printf("a = %d\n", a);
	sscanf(argv[2], "%d", &b);
	printf("b = %d\n", b);
	sscanf(argv[3], "%d", &c);
	printf("c = %d\n", c);
	printf("a + b + c = %d\n", a + b + c);
	return 0;
}
