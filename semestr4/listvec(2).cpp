#include <iostream>
#include <vector>
#include <list>
using namespace std;

void g (vector <int> & v, list <int> & l) {
	vector <int> :: const_iterator p=v.begin();
	for (unsigned int i=0; i<v.size(); i++) {
		if ((*p % 2)==0)
			l.push_back(v[i]);
		p++;
		}
	list <int> :: const_iterator q=l.begin();
	while (q!=l.end()) {
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
		v.push_back(k);
		}
	g(v,l);
	}
