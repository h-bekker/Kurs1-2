#include <iostream>
#include <list>
using namespace std;

list <double> pushmid(list <double> l) {
	list <double> :: const_iterator p=l.begin();
	double sum=0;
	while (p!=l.end()) {
		sum+=*p;
		p++;
		}
	double add=sum/l.size();
	l.push_back(add);
	return l;
	}

int main() {
	list <double> l;
	double n;
	int k;
	cin >> k;
	for (int i=0; i<k; i++) {
		cin >> n;
		l.push_back(n);
		}
	l=pushmid(l);
	list <double> :: const_iterator p=l.begin();
	while (p!=l.end()) {
		cout << *p << " ";
		p++;
		}
	cout << endl;
	return 0;
	}