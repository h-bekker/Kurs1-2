#include <iostream>
using namespace std;

int main() {
	int n,m,k;
	int ans=0;
	cin >> n >> m;
	if (n>m)
		cout << 0 << endl;
	else
		if (n==m)
			cout << 1 << endl;
		else
			if ((m==n+1) || (n==1))
				cout << m << endl;
			else {
				k=1;
				while (m>=n) {
					ans+=m-k;
					k++;
					n++;
					}
				cout << ans << endl;
			}
	}					
				
			
