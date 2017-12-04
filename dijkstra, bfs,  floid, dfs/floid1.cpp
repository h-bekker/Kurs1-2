#include <iostream>
using namespace std;

int w[105][105];

int main() 
{
	int n,i,j,k;
	cin >> n;
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++)
			cin >> w[i][j];
	for (k=1; k<=n; k++)
		for (i=1; i<=n; i++)
			for (j=1; j<=n; j++)
				if (w[i][k]+w[k][j]<w[i][j])
					w[i][j]=w[i][k]+w[k][j];
	for (i=1; i<=n; i++) {
		for (j=1; j<=n; j++)
			cout << w[i][j] << " ";
		cout << endl;
	}
}

	
	
