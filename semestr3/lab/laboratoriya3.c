#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

struct node {
	char* word;
	int key;
	struct node* next;
	};

char* alloc(char* arr, int n) {
	if (!(arr=(char*) realloc(arr,n*sizeof(char)))) {
		printf("Error, memory no access\n");
		exit(1);
		}
	return arr;
	}

char* getword(int* kav, int* amp, char* ch) {
	int n=1, pos=0;
	char c='\0';
	char* str=NULL;
	if (!(str=(char*) calloc (n,sizeof(char)))) {
			printf("Error, first memory\n");		
			return 0; 
			}
	while ((scanf("%c",&c)==1) && (c!='\n') && (((c!=' ') && (c!='\t')) || (*kav==1))) {
		if ((c=='&') && (*amp!=2))
			*amp+=1;
		if (c=='"') {
			if (*kav==1)
				*kav=0;
			else
				*kav=1;
			}
		else {
			n++;
			str=alloc(str,n);
			str[pos]=c;
			pos++;
			}
		}
	if ((*amp==1) && ((pos>1) || ((pos==1) && (str[0]!='&'))))
		 *amp=2;
	*ch=c;
	if (pos==0) {
		free(str);
		return NULL;
		}
	n++;
	str=alloc(str,n);
	str[pos]='\0';
	return str;
	}

char* getlines(int* flag, int* amp) {
	char* str=NULL;
	char c='\0';
	int kav=0;
	str=getword(&kav, amp, &c);
	if (c=='\n')
		*flag=1;
	if (kav==1) {
		printf("Wrong input. Please, try again\n");
		*flag=2;
		return NULL;
		}
	return str;
	}

void forheap(char** argv, int k) {
	int i;
	for (i=0; i<k; i++)
		free(argv[i]);
	free(argv);
	}

void mkcd(char** argv, int k, struct node* l) {
	int d;
	if((l->next)!=NULL) {
			if((d=chdir(l->next->word))==-1)
				perror("cd");
			}
	else
		if((d=chdir("/home/bekker"))==-1)
			perror("cd ");
	forheap(argv,k);
	}

void mkexec(char** argv, int k, int pid1) {
	int pid,fd1,fd2,fd3,fd4,fd5;
	if ((pid=fork())<0) {
		perror("fork");
		forheap(argv,k);
		return;
		}
	fd1=open("/dev/null",O_RDONLY);
	fd2=open("/home/bekker/core",O_WRONLY|O_CREAT,0666); 
	if (!pid) {
		if (pid1==1) {
			if ((pid=setsid())==-1) {	
				perror("setsid");
				return;
				} 
			printf("[%d] %d\n",1,getpid());
			fd3=dup2(fd1,0);
			fd4=dup2(fd1,1);
			fd5=dup2(fd2,2);
			close(fd1);
			close(fd2);
			close(fd3);
			close(fd4);	
			close(fd5);	
			}
		execvp(argv[0],argv);
		perror("exec");
		forheap(argv,k);
		exit(1);
		}
	}

void cmd(struct node* l) {
	int pid=0,i=0,n=1;
	char** arg=NULL;
	struct node* link=l;
	if (l==NULL)
		return;
	if (!(arg=(char**) calloc (n,sizeof(char*)))) {
			printf("Error, first pointer from pointer\n");		
			return;
			}
	while (link!=NULL) {
		if (!(arg[i]=(char*) calloc (strlen(link->word)+1,sizeof(char)))) {
			printf("Error, first pointer from arr\n");		
			return;
			}
		n++;
		if (!(arg=(char**) realloc (arg,n*sizeof(char*)))) {
			printf("Error, memory no access for pointer\n");		
			return;
			}
		arg[i]=strcpy(arg[i],link->word);
		i++;
		link=link->next;
		}
	arg[i]=NULL;
	link=l;
	while (link->next!=NULL)
		link=link->next;
	if (strcmp(link->word,"&")==0)
		pid=1;		
	if (strcmp(arg[0],"cd")==0) {
		mkcd(arg,i,l);
		return;
		}
	mkexec(arg,i,pid);
	forheap(arg,i);
	}

struct node* newl(char* w) {
	struct node* p;
	p=(struct node*) calloc (1,sizeof(*p));
	if (!(p->word=(char*) calloc (strlen(w)+1,sizeof(char)))) {
			printf("Error, first memory\n");		
			return 0; 
			}
	p->word=strcpy(p->word,w);
	p->key=1;
	p->next=NULL;
	return p;
	}

struct node* pushback(struct node* l, struct node* p) {
	struct node* q;
	q=l;
	if (q==NULL)
		l=p;
	else { 
		while (q->next!=NULL) 
			q=q->next;
		q->next=p;
		}
	return l;
	}

void deletelist(struct node* l) {
	struct node* p;
	while (l!=NULL) {
		p=l;
		l=l->next;
		free(p->word);
		free(p);
		}
	}

void printlist(struct node* l) {
	struct node* p=l;
	if (p==NULL) 
		printf("No correct words\n");
	while (p!=NULL) {
		printf("%s\n",p->word);
		p=p->next;
		}
	}

int main(int argc, char** argv) {
	struct node* list = NULL;
	struct node* link = NULL;
	char* str;
	int flag, amp=0;
	while (!feof(stdin)) {
		flag=0;
		str=getlines(&flag, &amp);
		if (str!=NULL) {
			link=newl(str);
			list=pushback(list,link);
			}
		if (flag!=0) {
			if ((flag==1) && (amp!=2))			 
				cmd(list);
			if (amp==2)
				printf("Wrong input. & not in the end. Please, try again\n");			
			deletelist(list);
			list=NULL;
			amp=0;
			}
		free(str);			
		}
	return 0;
	}
