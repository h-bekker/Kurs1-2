#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void) {
	int n,k;
	char c='g';
	if (n=open("file", O_RDWR|O_CREAT, 0777)==-1) {
		printf("Error\n");
		close(n);
		exit(1);
		}
	//lseek(n,5,SEEK_SET);
	write(n,&c,sizeof(char));
	close(n);
	return 0;
	} 
	//поменять 5 символ
