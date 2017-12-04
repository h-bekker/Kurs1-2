#include <iostream>
using namespace std;

int main() {
	int n,m;
	int mask=0;
	cin >> n >> m;
	mask|=1<<n|1<<m;
	cout << mask << endl;
	}
