#include <iostream>
using namespace std;

char c;

void gc(){cin>>c;}

bool scan_G ( ) {
	enum state { F, A, B, S, ER };
	state CS; // CS - текущее состояние
	CS = S;
	do { gc ();
		switch (CS) {
			case S:
				if (c == '1') { CS = A;}
				else if (c == '@') { CS = F; }
					else if (c != '0') { CS = ER; }
				break;
			case A:
				if (c == '0') { CS = B;}
				else if (c == '@') { CS = F; }
					else if (c != '1') CS = ER;
				break;
			case B:
				if (c == '0') { CS = S;}
				else CS = ER;
				break;
		}
	} while (CS != F && CS != ER);
	if (CS == ER)
		return false;
	else
		return true;
	}

int main() {
	cout << scan_G() << endl;
	}
