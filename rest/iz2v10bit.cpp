#include <iostream>
using namespace std;

int main() {
	int n,t,p;
	int k=0,s=0;
	cin >> n;
	while (n!=0) {
		p=1;
		t=n % 10;
		n=n/10;
		if (t==1) {
			for (int i=0; i<k; i++)
				p*=2;
			s+=p;
			}
		k++;
		}	
	cout << s << endl;;
	}
