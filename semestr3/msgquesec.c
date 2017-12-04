#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

struct {
	unsigned long mtype;
	char* data;
	} message ;
	
int main() {
	key_t key;
	int msgid, n=256;
	//if (key=ftok("/bin/kill",44)==-1) {
		//perror("ftok");
		//exit(1);
		//}
	key=ftok("/bin/kill",56);
	printf("%d\n",key);
	msgid=msgget(key,0666);
	if (!(message.data=(char*) calloc (n,sizeof(char)))) {
		printf("Error\n");		
		return 0; 
		}
	while(1) {
		msgrcv(msgid, (struct msgbuf*) (& message), n-1, 1, 0);
		printf("%s\n",message.data);
		if (message.data[0]=='q'||message.data[0]=='Q')
			break;	
		}
	exit(0);
	}
		
