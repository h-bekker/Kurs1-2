#include <iostream>
using namespace std;

int main() {
	int n,m,k,t,ans;
	cin >> n;
	m=n;
	k=-1;
	while (m!=0) {
		m>>=1;
		k++;
		}
	m=n;
	ans=n;
	t=m % 2;
	m>>=1;
	m|=(t<<k);
	if (m>ans)
		ans=m;
	while (m!=n) {
		t=m % 2;
		m>>=1;
		m|=(t<<k);
		if (m>ans) 
			ans=m;
		}
	cout << ans << endl;
	}
