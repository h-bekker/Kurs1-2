#include <stdio.h>
#include <stdlib.h>

struct tree {
	int key;
	struct tree* left;
	struct tree* right;
	};

struct tree* new(int n) {
	struct tree* p;
	p=(struct tree*) calloc (1,sizeof(*p));
	p->key=n;
	p->left=NULL;
	p->right=NULL;
	return p;
	}

struct tree* insert(struct tree* p, struct tree* q) {
	if (p==NULL) 
		p=q;
	else
		if (p->key>q->key) {
			if (p->left==NULL)
				p->left=q;
			else
				insert(p->left,q);
			}
		else {
			if (p->right==NULL)
				p->right=q;
			else
				insert(p->right,q);
			}
	return p;
	}

void printlist(struct tree* l) {
	if (l!=NULL) {
		printlist(l->left);
		printf("%d ",l->key);
		printlist(l->right);
		}
	}

int main(void) {
	struct tree* root = NULL;
	struct tree* link = NULL;
	int n;
	while (scanf("%d",&n)==1) {
		link=new(n);
		root=insert(root,link);
		}
	printlist(root);
	printf("\n");	
	return 0;
	}
