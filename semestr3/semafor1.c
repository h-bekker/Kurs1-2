#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
	int n;
	int sem_id, sem_fd;
	int i, fd;
	struct sembuf op[2];
	pid_t pid1, pid2;
	key_t key;
	
	pid2 = fork();
	if (pid2 == -1) {
		perror("fork");
		return 1;
	}
	if (pid2 == 0) {
		key=ftok("/bin/kill", 40);
		if ((sem_id = semget(key, 1, IPC_CREAT)) < 0) {
			perror("semget");
			return 1;
		}
		if ((fd = open("file.txt", O_CREAT|O_TRUNC|O_RDWR)) == -1) {
			perror("open");
			return 1;
		}
		while(1) {
			//struct sembuf op[0]={{0,-1,0}};
			op[1].sem_num = 0;
			op[1].sem_op = -1;
			op[1].sem_flg = 0;
			semop(sem_id, &op[0], 1);
			read(fd, &n, sizeof(int));
			n++;
			printf("Second son: %d\n", n);
			write(fd, &n, sizeof(int));
			sleep(1);
			//struct sembuf op[1]={{0,1,0}};
			op[0].sem_num = 0;
			op[0].sem_op = 1;
			op[0].sem_flg = 0;
			semop(sem_id, &op[1], 1);
		}
		semctl(sem_id, 0, IPC_RMID, 0);
		exit(0);
	}
	wait(NULL);
	return 0;
}	
