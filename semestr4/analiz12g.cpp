#include <iostream>
using namespace std;

char c;

void gc(){cin>>c;}

bool scan_G ( ) {
	enum state { H, A, C, BS, AS, S, S1, ER };
	state CS; // CS - текущее состояние
	CS = H;
	do { gc ();
		switch (CS) {
			case H:
				if (c == '0') { CS = C; }
				else CS = ER;
				break;
			case C:
				if (c == '1') { CS = A; }
				else if (c != '0') { CS = ER; }
				break;
			case A:
				if (c == '0') { CS = BS; }
				else CS = ER;
				break;
			case BS:
				if (c == '1') { CS = AS; }
				else CS = ER;
				break;
			case AS:
				if (c == '0') { CS = BS; }
				else if (c == '1') { CS = S; }
					else CS = ER; 
				break;
			case S:
				if (c == '@') { CS = S1; }
				else CS = ER;
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
