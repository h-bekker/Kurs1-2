#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main(void) {
	int fd1,fd2,pid=1;
	time_t curtime ;  
	struct tm *loctime ;
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
		read(fd1,&pid,sizeof(int));
		curtime = time(NULL);
		write(fd2,&curtime,sizeof(int));
		sleep(1);
		}
	close(fd1);
	close(fd2);
	unlink("fifo1");
	unlink("fifo2");
	}
