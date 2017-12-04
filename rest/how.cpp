#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream f;
	string a;
	f.open("dic.txt");
	int k=0;
	while(!f.eof()) {
		k++;
		f >> a;
		cout << a << endl;
		}
	return 0;
	}
