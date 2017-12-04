#include <iostream>
#include <vector>
using namespace std;

int dlina (vector <int> v) {
	int res=1;
	int ans=0;
	int what=v[0];
	for (int i=1; i<v.size(); i++)
		if (v[i]==what)
			res++;
		else {
			what=v[i];
			if (res>ans)
				ans=res;
			res=0;
			}
	return ans;
	}

int main() {
	vector <int> v;
	int n;
	cin >> n;
	int k;
	for (int i=0; i<n; i++)
	{
		cin >> k;
		v.push_back(k);
	}
	int ans;
	ans=dlina(v);
	cout << ans << endl;
	}
