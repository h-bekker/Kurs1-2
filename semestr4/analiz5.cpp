#include <iostream>
using namespace std;

char c;

void gc(){cin>>c;}

bool scan_G ( ) {
	enum state { H, A, B, S, ER };
	state CS; // CS - текущее состояние
	CS = H;
	do { gc ();
		switch (CS) {
			case H:
				if (c == 'b') { CS = A;}
				else CS = ER;
				break;
			case A:
				if (c == 'b') { CS = A;}
				else if (c=='a') { CS = B; }
					else  if (c=='@') { CS = S; }
						else CS = ER;
				break;
			case B:
				if (c == 'b') { CS = A;}
				else CS = ER;
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
