#include <iostream>
using namespace std;

int main() {
	int n,k;
	int mask=0;
	cin >> n;
	int s=1;
	for (int i=0; i<n; i++)
		s*=2;
	for (int i=0; i<s; i++) {
		for (int j=0; j<n; j++) {
			k=i;
			k=k>>(n-j-1);
			k=k%2;
			cout << k;
			}
		cout << endl;
		}
	}
