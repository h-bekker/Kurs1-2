#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node* next;
	};

struct node* new(int n) {
	struct node* p;
	p=(struct node*) calloc (1,sizeof(*p));
	p->key=n;
	p->next=NULL;
	return p;
	}

int searchkey(struct node* l, int n) {
	struct node* p=l;
	while (p!=NULL) {
		if (p->key==n)
			return 1;
		p=p->next;
		}
	return 0;
	}

struct node* searchpos(struct node* l, int n) {
	struct node* p=l;
	if ((p==NULL) || (p->key>n))  
		return NULL; 
	struct node* q=p->next;
	while (q!=NULL)
		if (q->key<n) {
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
	q=searchpos(l,p->key);
	l=insert(l,q,p);
	return l;
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

struct node* ins(struct node* l, struct node* p) {
	struct node* t;
	t=new(p->key);
	l=pushback(l,t);
	p=p->next;
	return l;
	}

struct node* mergelist(struct node* l, struct node* p) {
	struct node* q;
	struct node* r;
	struct node* s;
	struct node* t;
	q=NULL;
	r=l;
	s=p;
	while ((r!=NULL) && (s!=NULL))
		if (r->key>s->key) {
			t=new(s->key);
			q=pushback(q,t);
			s=s->next;
			//q=ins(q,s);			
			}
		else {
			t=new(r->key);
			q=pushback(q,t);
			r=r->next;
			//q=ins(q,r);
			}
	if (s!=NULL)
		r=s;			
	while (r!=NULL) {
		t=new(r->key);
		q=pushback(q,t);
		r=r->next;
		//q=ins(q,r);		
		}
	return q;
	}

void printlist(struct node* l) {
	struct node* p=l;
	while (p!=NULL) {
		printf("%d ",p->key);
		p=p->next;
		}
	printf("\n");
	}

int main(void) {
	struct node* list1 = NULL;
	struct node* list2 = NULL;
	struct node* list = NULL;
	struct node* link = NULL;
	int n;
	while (scanf("%d",&n)==1) {
		link=new(n);
		list1=pushsort(list1,link);
		}
	while (scanf("%d",&n)==1) {
		link=new(n);
		list2=pushsort(list2,link);
		}
	list=mergelist(list1,list2);
	printlist(list);
	return 0;
	}
