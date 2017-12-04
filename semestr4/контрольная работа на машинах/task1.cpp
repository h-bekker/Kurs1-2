#include <iostream>
using namespace std;

class B {
		int x;
		int y;
	public:
		B(int a, int b=5) {
			x=a;
			y=b;
			}
		int get() { return x+y; }
		B operator+=(B b) {x+=b.x; y+=b.y; return *this; }
		~B() {}
	};	

int main(){
	B b1(1), b2(2,3), b3(b1);
	b1+= b2+= b3;
	cout << b1.get() << ' ' << b2.get() << ' ' << b3.get() << endl;
	return 0;
}
