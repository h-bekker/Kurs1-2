#include <iostream>
using namespace std;

int main() {
	int n,m;
	int mask=0;
	cin >> n >> m;
	n=n>>m;
	n=n % 2;
	cout << n << endl;
	}
