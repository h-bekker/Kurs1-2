#include <iostream>
#include <vector>
using namespace std;

int g(vector <double*> & v) {
	vector <double*> :: iterator p=v.begin();
	vector <double*> :: const_iterator q=v.begin();
	q++;
	int ans=0;
	while ((q!=v.end()) && (p!=v.end())) {
		if (**q<0) {
			**p=0;
			ans++;
			}
		q+=2;
		p+=2;
		}
	vector <double*> :: reverse_iterator r=v.rbegin();
	while (r!=v.rend()) {
		cout << **r << " ";
		r++;
		}
	cout << endl;
	return ans;
	}

int main() {
	vector <double*> v;
	int n;
	cin >> n;
	double* d=new double[n];
	for (int i=0; i<n; i++) {
		cin >> d[i];
		v.push_back(&d[i]);
		}
	vector <double*> :: iterator r=v.begin();
	n=g(v);
	cout << n << endl;
	return 0;
	}
