#include <iostream>
using namespace std;

int main() {
	int n,k;
	cin >> n;
	while (n!=0) {
		k=n % 2;
		n=n>>1;
		cout << k;
		}
	cout << endl;
	}
