#include <iostream>
using namespace std;

int w[105][105], d[105][105];

int main() 
{
	int n,i,j,k;
	cin >> n;
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++)
			cin >> w[i][j];
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++)
			if (w[i][j]>0) 
				d[i][j]=w[i][j];
			else
				d[i][j]=100005;
	for (k=1; k<=n; k++)
		for (i=1; i<=n; i++)
			for (j=1; j<=n; j++)
				if (d[i][k]+d[k][j]<d[i][j])
					d[i][j]=d[i][k]+d[k][j];
	int max=0;
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++)
			if ((i!=j) && (d[i][j]!=100005))
				if (d[i][j]>max)
					max=d[i][j];
	cout << max << endl; 
}

	
	
