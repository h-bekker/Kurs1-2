#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char* getlines(void) {
	char* str=NULL;
	char c;
	int n=1, pos=0, kav=0;
	if (!(str=(char*) calloc (n,sizeof(char)))) {
		printf("Error, first memory\n");		
		return NULL; 
		}
	while ((scanf("%c",&c)==1) && (c!='\n') && (((c!=' ') && (c!='\t')) || (kav==1))) {
		if (c=='"') {
			if (kav==1)
				kav=0;
			else
				kav=1;
			}
		else {
			n++;
			str=alloc(str,n);
			str[pos]=c;
			pos++;
			}
		}
	if (kav==1) {
		printf("Wrong input. Please, try again\n");
		exit(1);
		}
	if (pos==0) {
		free(str);
		return NULL;
		}
	n++;
	str=alloc(str,n);
	str[pos]='\0';
	return str;
	}

struct node* newl(char* w) {
	struct node* p;
	p=(struct node*) calloc (1,sizeof(*p));
	p->word=w;
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
	FILE* f;
	//int len, flag, last=0;
	if ((f=freopen(argv[1],"r",stdin))==NULL) {
		printf("Error!!!\n");
		exit(1);
		}
	while (!feof(stdin)) {
		str=getlines();
		if (str!=NULL) {
			link=newl(str);
			list=pushback(list,link);
			//free(str);		
			}		
		}
	printlist(list);
	deletelist(list);
	fclose(f);
	return 0;
	}
