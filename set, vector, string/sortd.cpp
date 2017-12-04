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
	if (n % 2 != 0) 
	{
	set <int>:: iterator p;
	for (p=s.begin(); p!=s.end(); p++)
		cout << *p << endl;
	}
	else
	{
	set <int>:: reverse_iterator q;
	for (q=s.rbegin(); q!=s.rend(); q++)
		cout << *q << endl;
	}
}
