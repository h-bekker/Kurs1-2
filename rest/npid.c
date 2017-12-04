#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <signal.h>
#include <sys/types.h>

int main() {
	int pid[5], a[5];
	int n,i,ans,ind=0,min=0;
	srand(time(NULL));
	n=(rand() % 500)+3700;
	printf("rand number:%d\n",n);
	for (i=0; i<5; i++) {
		if ((pid[i]=fork())<0) {
			perror("fork");
			return 1;
			}
		if (!pid[i]) {
			while(1) {
				}
			}
		else {
			printf("son%d:%d\n",i+1,pid[i]);
			a[i]=abs(pid[i]-n);
			}
		}
	min=a[0];
	ind=0;
	for (i=1; i<5; i++) {
		if (a[i]<min) {
			min=a[i];
			ind=i;
			}
		}
	printf("ans:%d\n",pid[ind]);
	for (i=0; i<5; i++)
		kill(pid[i],SIGINT);
	return 0;
	}
	
