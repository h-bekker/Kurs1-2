#include <iostream>
using namespace std;

char c;

void gc(){cin>>c;}

bool scan_G ( ) {
	enum state { H, BD, BC, S, ER };
	state CS; // CS - текущее состояние
	CS = H;
	do { gc ();
		switch (CS) {
			case H:
				if (c == '0') { CS = BD; }
				else CS = ER;
				break;
			case BD:
				if (c == '1') { CS = BC; }
				else if (c != '0') { CS = ER; }
				break;
			case BC:
				if (c == '@') { CS = S; }
				else if (c != '1') { CS = ER; }
				break;
		}
	} while (CS != S && CS != ER);
	if (CS == ER)
		return false;
	else
		return true;
	}

int main() {
	cout << scan_G() << endl;
	}
