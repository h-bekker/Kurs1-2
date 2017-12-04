#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
	int fd1,fd2,pid=1;
	time_t curtime;  
	struct tm *loctime ;
	fd1=open("fifo1",O_RDWR);
	fd2=open("fifo2",O_RDWR);
	while(1) {
		write(fd1,&pid,sizeof(int));
		read(fd2,&curtime,sizeof(int));
		if (!(loctime=(struct tm*) calloc (1,sizeof(struct tm)))) {
			perror("loctime");
			return 1;
			} 
		loctime = localtime (&curtime ); 
		fputs(asctime(loctime), stdout ); 
		sleep(1);
		}
	close(fd1);
	close(fd2);
	}
