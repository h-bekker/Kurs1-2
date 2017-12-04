#include <iostream>
using namespace std;

char c;

void gc(){cin>>c;}

bool scan_G ( ) {
	enum state { H, A, AB, S, ER };
	state CS; // CS - текущее состояние
	CS = H;
	do { gc ();
		switch (CS) {
			case H:
				if (c == 'x') { CS = A;}
				else CS = ER;
				break;
			case A:
				if (c == 'x') { CS = A;}
				else if (c=='y') { CS = AB; }
					else CS = ER;
				break;
			case AB:
				if (c == 'x') { CS = A;}
				else if (c=='@') { CS = S; }
					else if (c != 'y') CS = ER;
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
