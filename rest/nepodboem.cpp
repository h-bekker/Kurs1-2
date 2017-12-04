#include <iostream>
using namespace std;

int g[100005],h[100005];

int main() {
	int n,x,y;
	long long int m,p,q;
	cin >> n >> m;
	p=q=n;
	for (long long int i=0; i<m; i++) {
		cin >> x >> y;
		if (g[x]==0) {
			p--;
			g[x]=1;
			}
		if (h[y]==0) {
			q--;
			h[y]=1;
			}
		cout << p*q << " ";
		}
	cout << endl;
	}
		
