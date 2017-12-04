#include <stdio.h>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

multiset <int> s;
multiset <int> :: reverse_iterator it;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("input.txt", "w", stdout);
	int n,k,a;
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a;
		s.insert(a);
		}
	int ans=0;
	it=s.rbegin();
	while (it!=s.rend() && k>0) {
		ans+=*it;
		it++;
		k--;
		}
	cout << ans << endl;
	}
