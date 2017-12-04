#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>

struct {
	long mestype;
	char mes[100];
	} messageto;

struct {
	long mestype;
	long mes;
	} messagefrom;

int main() {
	key_t key;
	int mesid;
	key=ftok("/bin/kill",44);
	printf("%d\n",key);
	mesid=msgget(key,0666|IPC_CREAT|IPC_EXCL);
	while(1) {
		msgrcv(mesid, &messagefrom, sizeof(messagefrom)-sizeof(long),1,0);	
		messageto.mestype=messagefrom.mes;
		strcpy(messageto.mes,"Message for client");
		msgsnd(mesid, &messageto, sizeof(messageto)-sizeof(long),0);
		}
	return 0;
	}