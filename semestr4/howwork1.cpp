#include <iostream>

using namespace std;

struct X;
void f(X & x,int n);
const int P=1;
int const Q=1;
const int R=1;
struct X{
	X(){try{ f(*this,P); cout << 1 << endl;}
		catch(X) { cout << 2 << endl;}
		catch(int) {cout << 3 << endl;}
	}
	X (X &) {cout << 4 << endl;}
	~X() {cout << 5 << endl;}
};

struct Y : X { Y() {f(*this,Q); cout << 6 << endl;}
	Y ( Y &) { cout << 7 << endl;}
	~ Y () {cout << 8 << endl;}
};

void f(X & x,int n) { try { if (n<0) throw x; if (n>0) throw 1; cout << 9 << endl;
	}
	catch(int) { cout << 10 << endl;}
	catch(X & a) { cout << 11 << endl; f(a,R);
		cout << 12 << endl;
		throw;
	}
}

int main(void){
	try {Y a;}
	catch(...) {
		cout << 12 << endl;
		return 0;
	}
	cout << 14 << endl;
	return 0;
}