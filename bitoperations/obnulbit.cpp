#include <iostream>
using namespace std;

int main() {
	int n,m;
	int mask=0;
	cin >> n >> m;
	for (int i=0; i<m; i++)
		mask|=1<<i;
	n&=mask;
	cout << n << endl;
	}
