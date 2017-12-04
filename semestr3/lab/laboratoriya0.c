#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char* word;
	int key;
	struct node* next;
	};

int min(int a, int b) {
	if (a>b) 
		return b;
	else
		return a;
	}

int checkw(char* w) {  //проверка на то, является ли слово "правильным"
	if (w==NULL) {
		return 0;
		}
	int i, k=strlen(w);
	for (i=0; i<k; i++) {
		if ((w[i]<'A') || (w[i]>'z') || ((w[i]>'Z') && (w[i]<'a')))
			return 0;
		}
	return 1;
	}

char* getlines(void) {
	char* str;
	char c;
	int n=4, pos=0, t=1;
	str=(char*)malloc(n*sizeof(char));
	if (!(str=(char*) calloc (n,sizeof(char)))) {
		printf("Error\n");		
		return NULL; 
		}
	while ((scanf("%c",&c)==1) && (c!=' ') && (c!='\n') && (c!='\t')) {
		if (pos==n) {
			n+=4;
			if (!(str=(char*) realloc(str,n*sizeof(char)))) {
				printf("Error\n");
				return NULL;
				}
			}
		if ((c>='A') && (c<='Z'))
			c=c-'A'+'a';
		str[pos]=c;
		pos++;
		}
	if (pos==n) {
		n+=1;
		if (!(str=(char*) realloc(str,n*sizeof(char)))) {
			printf("Error\n");
			return NULL;
			}
		}
	if (pos==0)
		return NULL;
	str[pos]='\0';
	return str;
	}

struct node* new(char* w) {
	struct node* p;
	p=(struct node*) calloc (1,sizeof(*p));
	p->word=w;
	p->key=1;
	p->next=NULL;
	return p;
	}

int cmp(char* v, char* w) {
	int i;
	int len=min(strlen(v),strlen(w));
	for (i=0; i<=len; i++) {
		if (*(v+i)>*(w+i))
			return 1;
		else
			if (*(v+i)<*(w+i))
				return 0;
		}
	return 2;
	}

int searchword(struct node* l, char* w) {
	struct node* p=l;
	while (p!=NULL) {
		if (strcmp(p->word,w)==0) {
			p->key+=1;
			return 1;
			}
		p=p->next;
		}
	return 0;
	}

struct node* searchpos(struct node* l, char* w) {
	struct node* p=l;
	if ((p==NULL) || cmp(l->word,w))  
		return NULL; 
	struct node* q=p->next;
	while (q!=NULL)
		if (cmp(w,q->word)) {
			p=p->next;
			q=q->next;
			}
		else
			return p;
	return p;
	}

struct node* insert(struct node* l, struct node* p, struct node* q) {
	struct node* r=l;
	struct node* t;
	if (p==NULL) {
		q->next=r;
		r=q;
		return r;
		}
	while (r!=p)
		r=r->next;
	t=r->next;
	r->next=q;
	q->next=t;
	return l;
	}

struct node* pushsort(struct node* l, struct node* p) {
	struct node* q;
	q=searchpos(l,p->word);
	l=insert(l,q,p);
	return l;
	}

struct node* pushfront(struct node* l, struct node* p) {
	p->next=l;
	l=p;
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
		printf("%s - %d\n",p->word,p->key);
		p=p->next;
		}
	}

int main(int argc, char** argv) {
	struct node* list = NULL;
	struct node* link = NULL;
	char* str;
	FILE* f;
	int len, flag, last=0;
	if ((f=freopen(argv[1],"r",stdin))==NULL) {
		printf("Error!!!\n");
		exit(1);
		}
	str=getlines();
	flag=checkw(str);
	if (flag) {
		link=new(str);
		list=pushfront(list,link);
		}
	while (!feof(stdin)) {
		str=getlines();
		if (str!=NULL) {
			flag=checkw(str);
			if (flag) {
				flag=searchword(list,str);
				if (flag==0) {
					link=new(str);
					list=pushsort(list,link);
					}		
				}
			}		
		}
	printlist(list);
	deletelist(list);
	fclose(f);
	return 0;
	}
