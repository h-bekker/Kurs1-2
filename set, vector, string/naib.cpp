#include <iostream>
#include <string>
using namespace std;

int a[30];

int main() {
	int k;
	string s;
	cin >> k >> s;
	int p=0,q=0;
	while (p<k) {
		if (a[s[q]-'a']!=1) {
			a[s[q]-'a']=1;
			p++;
			}
		q++;
		}
	cout << p << endl;
	}
