#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v[100005];

int main()
{
	int n,m;
	cin >> n >> m;
	int k,l;
	for (int i=1; i<=n; i++)
		v[i].push_back(0);
	for (int i=1; i<=m; i++)
	{	
		cin >> k >> l;
		v[k][0]++;
		v[l][0]++;
		v[l].push_back(k);
		v[k].push_back(l);
	}	
	for (int i=1; i<=n; i++)
	{	
		cout << i << ": ";
		for (int j=0; j<=v[i][0]; j++)
			cout << v[i][j] << " ";
		cout << endl;
	} 
}	 
	



