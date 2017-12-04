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
typedef char brd[3][3];
void display(brd b);
int checkwin(brd b);
int main() {
	int player=0;
	int winner=0;
	int choice=0;
	int i=0,r,c,k,j,p;
	int pid2;
	int shm_id, sem_id;
	struct sembuf sop[2];
	key_t shm_key;
	brd b={{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
	brd *pointer;
	if ((pid2 = fork()) < 0) {
		perror("error-fork");
		return 1;
	}
	if (pid2 == 0) {
    	shm_key = ftok("/bin/kill", 5);
        if (shm_key == -1) {
        	perror("Could get sem_key");
        	return 1;
        	}
		if ((shm_id = shmget(shm_key, sizeof(brd), IPC_CREAT)) < 0) {
        	perror("shmget");
          	return 1;
			}
		pointer = (brd*) shmat(shm_id, NULL, 0);
        if ((sem_id = semget(shm_key, 1, IPC_CREAT|0666)) < 0) {
  	        perror("semget");
            return 1;
        	}
		printf("%d\n",sem_id);
		printf("%d\n",shm_id);
		//pointer=*b;
        while (1) {
			i=i+2;
			display(*pointer);
			sop[1].sem_op = -1;
           	sop[1].sem_num = 0;
           	sop[1].sem_flg = 0;
           	semop(sem_id, &sop[1], 1);
			choice=usermove(*pointer,i);
			r=--choice/3;
			c=choice%3;
			b[r][c]='o';
			pointer=*b;
			if (checkwin(*pointer))
				winner=1;
			display(*pointer);
			if (winner) {
				printf("\n Winner player: user\n");
				break;
				}
			/*else
				printf("\n it is draw\n");*/
        	sop[0].sem_op = 1;
           	sop[0].sem_num = 0;
           	sop[0].sem_flg = 0;
       		semop(sem_id, &sop[0], 1);
        	}
		shmdt(shm_id);
       	semctl(sem_id, 0, IPC_RMID, 0);
       	exit(0);
        }
	wait(NULL);
	}
//////////////////////////////////////////////////////////////
void display(brd b) {
	int r,c;
	printf("\n");
	for (r=0; r<3; ++r) {
		if (r!=0)
			printf("---+---+---\n");
		for (c=0; c<3; ++c) {
                	if (c!=0)
                		printf("|");
			printf(" %c ", b[r][c]);
		}
	printf("\n");
	}
}
/////////////////////////////////////////////////////////////
int checkwin(brd b) {
	char c, ch[3], cv[3]; // ch-гориз, cv-верт
	int row, col, k;
	c=b[0][0];
	if (c==b[1][1] && c==b[2][2])
		return 1;
	c=b[0][2];
	if (c==b[1][1] && c==b[2][0])
		return 1;
	for (k=0; k<3; ++k) {
		ch[k]=b[k][0];
		cv[k]=b[0][k];
	}
	for (row=0; row<3; ++row) {
		int t=1;
		for (col=0; col<3; ++col)
			t=t && (ch[row]==b[row][col]);
		if (t)
			return 1;
	}
        for (col=0; col<3; ++col) {
                int t=1;
                for (row=0; row<3; ++row)
                        t=t && (cv[col]==b[row][col]);
                if (t)
                        return 1;
        }
	return 0;
}
///////////////////////////////////////////////////////////////////////
int usermove(brd b, int m) {
	int ch,t;
	int r,c;
	do {
		printf("please enter number: %c\n",'o');
		scanf("%d", &ch);
		t=ch-1;
		r=t/3;
		c=t%3;
	} while(t<0 || t>8 || b[r][c]>'9');
	return ch;
}
///////////////////////////////////////////////////////////////////////
int compmove(brd a, int m) {
	static int st=0;
	static const int pos[9]={5,1,3,7,9,2,4,6,8};
	brd b;
	char ch;
	int i,j,k,f=0;
	if (m==0)
		return 5;
//copy a -> b
        for (i=0; i<3; ++i)
                for (j=0; j<3; ++j)
			b[i][j]=a[i][j];
//проверка может ли компьютер выиграть одним ходом
	for (i=0; i<3; ++i)
	        for (j=0; j<3; ++j)
			if (b[i][j]<='9') {
				ch=b[i][j];
				b[i][j]='x';
				f=checkwin(b);
				if (f)
					return i*3+j+1;
				else
					b[i][j]=ch;
			}
//проверка может ли пользователь выиграть одним ходом
        for (i=0; i<3; ++i)
                for (j=0; j<3; ++j)
                        if (b[i][j]<='9') {
                                ch=b[i][j];
                                b[i][j]='o';
                                f=checkwin(b);
                                if (f)
                                        return i*3+j+1;
                                else
                                        b[i][j]=ch;
                        }
	if (m==2) {
        	for (i=0; i<3; ++i)
	                for (j=0; j<3; ++j)
				if (b[i][j]=='o') {
					if ((i+j)%2==1) {
						st=3*i+j;
						if ((i==0 && j==1) || (i==1 && j==0))
							return 1;
						if ((i==1 && j==2) || (i==2 && j==1))
                                                        return 9;
                                         }
				}
	}
	if (m==4 && st) {
		switch (st) {
			case 1: return 4;
			case 3: return 2;
			case 5: return 8;
			case 7: return 6;
		}
	}
	for (k=0; k<9; ++k) {
		int l=pos[k], t=l-1;
		i=t/3;
		j=t%3;
		if (b[i][j]<='9')
			return l;
	}

}
