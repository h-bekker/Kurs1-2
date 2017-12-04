#include <stdio.h>
#include <stdlib.h>

int max(int a, int b, int c) {
	if ((a>=b) && (a>=c))
		return a;
	else
		if ((b>=a) && (b>=c))
			return b;
		else
			return c;
	} 

int main(int argc, char** argv) {
	int x,y,z,ans;
	if (argc<4) 
		printf("Too few arguments\n");
	else {
		sscanf(argv[1],"%d",&x);
		sscanf(argv[2],"%d",&y);
		sscanf(argv[3],"%d",&z);
		printf("%d\n",max(x,y,z));
		}
	return 0;
	}
