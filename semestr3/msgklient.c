#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct {
	long mestype;
	long mes;
	} messageto;

struct {
	long mestype;
	char mes[100];
	} messagefrom;

int main() {
	key_t key;
	int mesid;
	long pid=getpid();
	key=ftok("/bin/kill",44);
	printf("%d\n",key);
	mesid=msgget(key,0666);
	messageto.mestype=1;
	messageto.mes=pid;
	msgsnd(mesid, &messageto, sizeof(messageto)-sizeof(long),0);
	msgrcv(mesid, &messagefrom, sizeof(messagefrom)-sizeof(long),pid,0);
	printf("%s\n", messagefrom.mes);
	return 0;
	}