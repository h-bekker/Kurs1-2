#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

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

char* getword(int* kav, char* ch) {
	int n=1, pos=0;
	char c='\0';
	char* str=NULL;
	if (!(str=(char*) calloc (n,sizeof(char)))) {
			printf("Error, first memory\n");		
			return 0; 
			}
	while ((scanf("%c",&c)==1) && (c!='\n') && (((c!=' ') && (c!='\t')) || (*kav==1))) {
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

char* getlines(int* flag) {
	char* str=NULL;
	char c='\0';
	int kav=0;
	str=getword(&kav, &c);
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

void mkexec(char** argv, int k) {
	int pid;
	if ((pid=fork())<0) {
		perror("fork");
		forheap(argv,k);
		return;
		}
	if (!pid) {
		execvp(argv[0],argv);
		perror("exec");
		forheap(argv,k);
		exit(1);
		}
	}

void cmd(struct node* l) {
	int d,i=0,n=8;
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
		n+=8;
		if (!(arg=(char**) realloc (arg,n*sizeof(char*)))) {
			printf("Error, memory no access for pointer\n");		
			return;
			}
		arg[i]=strcpy(arg[i],link->word);
		i++;
		link=link->next;
		}
	if (strcmp(arg[0],"cd")==0) {
		mkcd(arg,i,l);
		return;
		}
	mkexec(arg,i);
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
	int flag;
	while (!feof(stdin)) {
		flag=0;
		str=getlines(&flag);
		if (str!=NULL) {
			link=newl(str);
			list=pushback(list,link);
			}
		if (flag!=0) {
			if (flag==1)			 
				cmd(list);			
			deletelist(list);
			list=NULL;
			}
		free(str);			
		}
	return 0;
	}
