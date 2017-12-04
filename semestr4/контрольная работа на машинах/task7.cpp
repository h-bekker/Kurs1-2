#include <iostream>
#include <vector>
using namespace std;

template < class T > 
int count ( vector <T> v ) {
	int res = 0;
	for ( int i = 1; i < v.size(); i++ ) {
		if (v[i-1]*v[i]<0)
			res++;
	return res;
}

int main() {
	vector <int> v1;
	vector <double> v2; 
	int n;
	cin >> n;
	int k;
	for (int i=0; i<n; i++)
	{
		cin >> k;
		v1.push_back(k);
	}
	double d;
	for (int i=0; i<n; i++)
	{
		cin >> d;
		v2.push_back(d);
	}
	int ans;
	ans=count <int> (v1);
	cout << ans << endl;
	ans=count <double> (v2);
	cout << ans << endl;
	}
