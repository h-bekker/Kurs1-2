#include <iostream>
using namespace std;

template <class T>
class List {
	public:
		T key;
		List* next;
	public:
		List() {key=0; next=NULL; } 
		List operator=(const List <T> &l) {key=l.key; next=l.next; return *this; }
		bool empty() { if (next==NULL) return true; else return false; }; 
		void printlist(const List <T> &);
		List& pushfront(T);
		//List& pushback(T);
		int numb(const T&);
		//void pop(List l);
		~List() {}
	};

template <class T>
void List <T> :: printlist (const List <T> & l) {
	List link=l;
	if (empty()) {
		cout << "List is empty!\n";
		return;
		}
	do {
		cout << link.key << " ";
		link=*(link.next);
		}
		while (link.next!=NULL);
	cout << link.key << endl;
	}

template <class T>
List <T> & List <T> :: pushfront (T k) {
	List* link=new List;	
	link->key=k;
	link->next=next;
	next=link;
	return *this;
	}

template <class T>
List <T> & List <T> :: pushback (T k) {
	List* l=new List;
	l=next;
	while (l!=NULL) {
		l=l->next;
		}
	cout << key << endl;
	l->key=k;
	cout << key << endl;
	l->next=NULL;
	cout << key << endl;
	cout << next->key << endl;
	return *this;
	}

template <class T>
int List <T> :: numb (const T & k) {
	List* link=next;
	int ans=0;
	do {
		if (link->key==k)
			ans++;
		link=link->next;
		}		
		while (link!=NULL);
	delete link;
	return ans;
	}


int main() {
	int k,t;
	List <int> l;
	cin >> k;
	for (int i=0; i<k; i++)
		l=l.pushfront(i+1);
	l.printlist(l);
	cin >> t;
	k=l.numb(t);
	cout << k << endl;
	}
