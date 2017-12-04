#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int pid1, pid2, status;
	int fds1[2], fds2[2];
	int k;
	srand(time(NULL));
	k=rand() % 1000;
	if (pipe(fds1)) {
		perror("pipe");
		return 1;
		} 
	if (pipe(fds2)) {
		perror("pipe");
		return 1;
		}
	if ((pid1=fork())==-1) {
		perror("fork");
		return 1;
		}
	if ((pid2=fork())==-1) {
		perror("fork");
		return 1;
		}
	if (pid1==0) { //son1
		while(1) {
			//close(fds1[0]);	
			close(fds2[1]);
			write(fds1[1],&k,sizeof(int));	
			read(fds2[0],&k,sizeof(int));
			printf("son1: %d\n",k);
			k++;			
			close(fds1[1]);
			close(fds1[0]);
			close(fds2[1]);
			close(fds2[0]);
			sleep(1);
			}
		}
	if (pid2==0) { //son2
		while(1) {
			//close(fds2[0]);
			close(fds1[1]);
			read(fds1[0],&k,sizeof(int));
			printf("son2: %d\n",k);
			k++;
			write(fds2[1],&k,sizeof(int));
			close(fds1[1]);
			close(fds1[0]);
			close(fds2[1]);
			close(fds2[0]);
			sleep(1);
			}
	
		}
	/*if ((pid1==0) && (pid2==0)) { //son1
		while(1) {
			//dup2(fds1[1],1);
			//dup2(fds2[0],0);
			write(fds2[1],&k,sizeof(int));
			read(fds2[0],&k,sizeof(int));
			printf("son1: %d\n",k);
			k++;			
			write(fds1[1],&k,sizeof(int));	
			read(fds1[0],&k,sizeof(int));
			printf("son2: %d\n",k);
			k++;
			close(fds1[1]);
			close(fds1[0]);
			close(fds2[1]);
			close(fds2[0]);
			sleep(1);
			}
		} */
	wait(&status);
	if (WIFSIGNALED(status))
		return WTERMSIG(status)+256;
	wait(&status);
	if (WIFSIGNALED(status))
		return WTERMSIG(status)+256;
	return WEXITSTATUS(status);
	}
