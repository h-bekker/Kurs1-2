#include <iostream>
using namespace std;

char c;

void gc(){cin>>c;}

bool scan_G ( ) {
	enum state { H, AS, S, S1, ER };
	state CS; // CS - текущее состояние
	CS = H;
	do { gc ();
		switch (CS) {
			case H:
				if (c == 'a') { CS = AS; }
				else if (c == 'b') { CS = S; }
					else CS = ER;
				break;
			case AS:
				if (c == '@') { CS = S1; }
				else if ((c != 'a') && (c != 'b')) { CS = ER; }
				break;
			case S:
				if (c == 'b') { CS = AS;}
				else if (c == '@') { CS = S1; }
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
