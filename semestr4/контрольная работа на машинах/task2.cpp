#include <iostream>
using namespace std;

class Cls{
	int i;
public:
	int operator=(Cls* C) {i=C->i; return i;};
	Cls(){ i = 1; }
};

void f(Cls *p, Cls *q){
	*p = *q;
}

int main() {
	Cls* C1;
	Cls* C2;
	f(C1,C2);
	return 0;
	}
