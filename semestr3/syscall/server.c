#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {
	int fd,pid;
	if (mkfifo("fifo",0666)<0) {
		perror("mkfifo");	
		return 1;
		}
	fd=open("fifo",O_RDONLY|O_NONBLOCK);
	while(read(fd,&pid,sizeof(int))!=-1) {
		printf("Server %d got message from %d\n", getpid(), pid);
		}
	close(fd);
	unlink("fifo");
	}
