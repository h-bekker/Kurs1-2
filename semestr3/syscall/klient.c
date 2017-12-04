#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {
	int fd,pid=getpid();
	fd=open("fifo",O_RDWR);
	write(fd,&pid,sizeof(int));
	close(fd);
	}
