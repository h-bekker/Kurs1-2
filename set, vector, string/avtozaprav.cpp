#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct par {
	int x;
	int y;
};

int cmp(par a, par b) {
	if (a.x<b.x)
		return 1;
	return 0;
}

vector <par> v;
vector <int> u;

int main() {
	int n,k;
	par t;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> t.x;
		t.y=i;
		v.push_back(t);
		}
	sort(v.begin(),v.end(),&cmp);
	u.push_back(v[1].x);
	for (int i=1; i<n-1; i++)
		u.push_back(v[i+1].x-v[i-1].x);
	int ans=u[0], ind=0;
	for (int i=1; i<n-1; i++)
		if (u[i]<ans) {
			ans=u[i];	
			ind=i;
			}
	cout << v[ind].y << endl;
	/*cout << ans << " " << ind << endl;
	for (int i=0; i<n; i++)
		cout << v[i].x << " " << v[i].y << endl;
	for (int i=0; i<n-1; i++)
		cout << u[i] << endl;*/
	}
