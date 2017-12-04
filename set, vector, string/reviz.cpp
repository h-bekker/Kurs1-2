#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	vector <int> v;
	int n;
	cin >> n;
	int k;
	for (int i=0; i<n; i++)
	{
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(),v.end());
	cout << v[0] << ' ' << v[1] << endl;
}
