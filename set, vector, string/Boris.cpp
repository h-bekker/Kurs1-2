#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

set <int> s;
set <int> :: iterator it;

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
	while (!s.empty() && k>0) {
		it=s.end();
		it--;
		ans+=*it;
		k--;
		s.erase(it);
		}
	cout << ans << endl;
	}
