#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main() 
{
	set <int> s;
	int n;
	cin >> n;
	int k;
	for (int i=0; i<n; i++)
	{
		cin >> k;
		s.insert(k);
	}
	int x;
	cin >> x;
	set <int>:: iterator p; 
	p=s.find(x);
	if (p!=s.end())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
	
