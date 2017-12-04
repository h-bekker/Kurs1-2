#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main(void) {
	int fd1,fd2,pid=getpid();
	struct tm *loctime ;
	fd1=open("fifo1",O_RDWR);
	fd2=open("fifo2",O_RDWR);
	while(1) {
		write(fd2,&pid,sizeof(int));
		read(fd1,&pid,sizeof(int));
		printf("%d\n",pid);
		pid++;
		sleep(1);
		}
	close(fd1);
	close(fd2);
	}
