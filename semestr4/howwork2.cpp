#include <iostream>
#include <vector>
#include <list>
using namespace std;

void g (vector <int> & v, list <int> & l, int n) {
	vector <int> :: const_iterator p=v.begin();
	for (unsigned int i=0; i<v.size(); i++) {
		if (*p>n)
			l.push_back(v[i]);
		p++;
		}
	}

int main() {
	vector <int> v;
	list <int> l;
	int n,k;
	cin >> n;
	for (int i=0; i<5; i++) {
		cin >> k;
		v.push_back(k);
		}
	g(v,l,n);
	list <int> :: const_iterator p=l.begin();
	while (p!=l.end()) {
		cout << *p << endl;
		p++;
		}	
	}
