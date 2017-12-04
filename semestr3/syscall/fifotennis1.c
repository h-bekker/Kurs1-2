#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {
	int fd1,fd2,pid=getpid();
	if (mkfifo("fifo1",0666)<0) {
		perror("mkfifo");	
		return 1;
		}
	if (mkfifo("fifo2",0666)<0) {
		perror("mkfifo");	
		return 1;
		}
	fd1=open("fifo1",O_RDWR);
	fd2=open("fifo2",O_RDWR);
	while(1){
		read(fd2,&pid,sizeof(int));
		printf("%d\n",pid);
		pid++;
		write(fd1,&pid,sizeof(int));
		sleep(1);
		}
	close(fd1);
	close(fd2);
	unlink("fifo1");
	unlink("fifo2");
	}
