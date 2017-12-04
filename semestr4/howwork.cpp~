#include <iostream>
using namespace std;

struct S {
	S(int a) {
		cout << this << endl;
		try { 
			if (a>0) throw *this;
			else 
				if (a<0)
					throw 0;
			}
		catch(S &) {cout << "SCatch_S&\n"; }
		catch(int) {throw;}
		cout << "SConstr\n";
		}
	S(const S & a) {cout << "Copy\n"; }
	~S() { cout << "Destr\n"; }
	};

int main() {
	try {
		S s1(1), s2(-2);
		cout <<"Main\n"; }
	catch(S &) {cout << "MainCatch_S&\n"; }
	catch(...) {cout << "MainCatch_...\n"; }
	return 0;
	}
