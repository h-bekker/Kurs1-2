#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct str {
	int r1;
	int r2;
	int r3;
	string s1;
	string s2;
};

int cmp(str a,str b)
{
	if ((a.r1+a.r2+a.r3)>(b.r1+b.r2+b.r3))
		return 1;
	return 0;
}

int main() 
{
	vector <str> v;
	int n;
	cin >> n;
	str x;
	for (int i=0; i<n; i++)
	{
		cin >> x.s1 >> x.s2 >> x.r1 >> x.r2 >> x.r3;
		v.push_back(x);
	}
	stable_sort(v.begin(),v.end(),&cmp);
	for (int i=0; i<n; i++)
		cout << v[i].s1 << " " << v[i].s2 << endl;
}
