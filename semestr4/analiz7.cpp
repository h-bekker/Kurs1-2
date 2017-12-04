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
				if ((c >= '0') && (c<='9')) { cout << c; CS = A; }
				else if (c=='@') { CS = S; }
				break;
			case A:
				if ((c > '9') || (c < '0')) {
					if (c == '.')
						cout << c;
					else if (c=='@') { CS = S; }
						else { cout << endl; CS = H; }
					}
				else 
					cout << c;
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