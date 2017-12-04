#include <iostream>
using namespace std;

class stack {
		int* elem;
		int curr;
		int size;
	public:
		stack(int s=1, int x=0) {elem=new int[s]; elem[0]=x; curr=1; size=s; };  
		stack(const stack &);
		~stack(){delete[] elem; };
		stack & operator=(const stack &a) {
			delete[] elem;
			elem=new int[a.curr];
			curr=a.curr;
			size=a.size;
			for (int i=0; i<a.curr; i++)
				elem[i]=a.elem[i];
			return *this;
			};
		stack & push(int x) {
			if (full()) {
				cout << "Stack is full" << endl;
				return *this;
				}
			elem[curr]=x;
			curr++;
			return *this;
			};	 
		int pop() {
			if (empty()) {
				cout << "Stack is full" << endl;
				return 0;
				}
			curr--;
			return elem[curr];
			};
		bool empty() {if (!curr) return true; else return false; };
		bool full() {if (size==curr) return true; else return false; }; 
	};	

stack:: stack(const stack &a) {
	elem=new int[a.curr];
	curr=a.curr;
	size=a.size;
	for (int i=0; i<a.curr; i++)
		elem[i]=a.elem[i];
	}

int main() {
	int x,k;
	cin >> k >> x;
	stack a(k,x);	
	for (int i=1; i<k; i++)
		a.push(i);
	cout << a.pop() << endl;
	return 0;
	}
