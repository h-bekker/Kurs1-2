#include <iostream>
using namespace std;

int main() {
	int n,m,k;
	cin >> n >> m;
	k=n;
	k^=1<<m;
	if (k>n)
		cout << n << endl;
	else
		cout << k << endl;
	}
