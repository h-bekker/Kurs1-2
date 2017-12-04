#include <iostream>
#include <vector>
#include <list>
using namespace std;

void g (list <int> & l, vector <int> & v) {
	list <int> :: const_iterator p=l.begin();
	for (unsigned int i=0; i<l.size(); i++) {
		if ((*p % 2)==0)
			v.push_back(*p);
		p++;
		}
	vector <int> :: const_iterator q=v.begin();
	while (q!=v.end()) {
		cout << *q << " ";
		q++;
		}	
	cout << endl;
	}

int main() {
	vector <int> v;
	list <int> l;
	int n,k;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> k;
		l.push_back(k);
		}
	g(l,v);
	}
