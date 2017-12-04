#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n;
set <pair<int,int> > s;
set <pair<int,int> > :: iterator it;
set <pair<int,int> > :: iterator ik;
vector <int> v;

int main() {
	int k,l,m,t;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> k;
		s.insert(make_pair(k,i));
		}
	it=s.begin();
	l=(*it).first;
	ik=it;
	it++;
	m=(*it).first;
	v.push_back(m);
	while (it!=s.end()) {
		it++;
		m=(*it).first-(*ik).first;
		ik++;	
		v.push_back(m);
		}
	it--;
	it--;
	v[v.size()-1]=(*ik).first-(*it).first;
	int ans=v[0];
	for (int i=1; i<v.size()-1; i++) {
		if (v[i]<ans) {
			ans=v[i];
			t=i;
			}
		}
	t++;
	it=s.begin();
	int p=1;
	while (t!=p) {
		it++;
		p++;
		}
	cout << (*it).second << endl;
	}
		
