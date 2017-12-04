#include <iostream>
using namespace std;

char c;

void gc(){cin>>c;}

bool scan_G ( ) {
	enum state { H, A, AS, S1, ER };
	state CS; // CS - текущее состояние
	CS = H;
	do { gc ();
		switch (CS) {
			case H:
				if (c == '0') { CS = A; }
				else CS = ER;
				break;
			case A:
				if (c == '0') { CS = AS; }
				else CS = ER;
				break;
			case AS:
				if (c == '1') { CS = A; }
				else if (c == '@') { CS = S1; }
					else if (c != '0') { CS = ER; }
				break;
		}
	} while (CS != S1 && CS != ER);
	if (CS == ER)
		return false;
	else
		return true;
	}

int main() {
	cout << scan_G() << endl;
	}