#include <iostream>
#include <vector>
#include <list>
using namespace std;

int g(const vector <double> & v, list <double> & l, int n) {
	vector <double> :: const_iterator p=v.begin();
	list <double> :: iterator q=l.begin();
	int ans=0;
	double flag=false;
	while ((p!=v.end()) && (q!=l.end())) {
		if (*p!=*q) {
			l.insert(q,1,*p);
			ans++;
			}
		q++;
		for (int i=0; i<n; i++) {
			p++;
			if (p==v.end())
				flag=true;
			}
		if (flag)
			break;
		}
	list <double> :: reverse_iterator r=l.rbegin();
	while (r!=l.rend()) {
		cout << *r << " ";
		r++;
		}
	cout << endl;
	return ans;
	}

int main() {
	vector <double> v;
	list <double> l;
	int n,k;
	double d;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> d;
		v.push_back(d);
		}
	cin >> k;
	for (int i=0; i<k; i++) {
		cin >> d;
		l.push_back(d);
		}
	cin >> n;
	cout << g(v,l,n) << endl;
	return 0;
	}	




