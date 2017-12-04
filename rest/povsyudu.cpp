#include <iostream>
using namespace std;

int a[300];

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i=0; i<s.length(); i++)
		a[s[i]]++;
	int ans=s.length(), k=0;
	string t=s;
	while (k<s.length()) {
		a[t[k]]--;
		if (a[t[k]]==0)
			break;
		else
			ans--;
		k++;
		}
	a[t[k]]++;
	k=s.length()-1;
	int an=s.length();
	while (k>0) {
		a[t[k]]--;
		if (a[t[k]]==0)
			break;
		else
			an--;
		k--;
		}
	if (an<ans)
		ans=an;
	cout << ans << endl;	
}
