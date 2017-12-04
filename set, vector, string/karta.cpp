#include <iostream>
#include <set>
using namespace std;

set <pair<int,int> > s;
set <pair<int,int> > :: iterator it1;
set <pair<int,int> > :: iterator it2;

int main() {
	int n,k;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> k;
		s.insert(make_pair(k,i));
		}
	it1=s.begin();
	it2=s.end();
	it2--;
	for (int i=1; i<=n/2; i++) {
		cout << (*it1).second << " " << (*it2).second << endl;
		it1++;
		it2--;
		}
	}
		
