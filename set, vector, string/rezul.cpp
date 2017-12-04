#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct str {
	int r;
	string s;
};

int cmp(str a,str b)
{
	if (a.r>b.r)
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
		cin >> x.s >> x.r;
		v.push_back(x);
	}
	sort(v.begin(),v.end(),&cmp);
	for (int i=0; i<n; i++)
		cout << v[i].s << endl;
}
