#include <iostream>
using namespace std;

int c;
void A ();
void B ();
void gc () {
	cin >> c;
	}
// текущий анализируемый символ
// считать очередной символ
void S () {
	cout << "S-->ABd, "; // применяемое правило вывода
	A();
	B();
	if ( c != 'd' )
		throw c;
	gc ();
	}
void A () {
	if ( c =='a' ) {
		cout << "A-->a, ";
		gc ();
		}
	else if ( c =='c' ) {
		cout << "A-->cA, ";
		gc ();
		A ();
		}
		else
			throw c;
	}

void B () {
	if ( c =='b' ) {
		cout << "B-->bA, ";
		gc ();
		A ();
		}
	else
		throw c;
	}

int main () {
	try {
		gc ();
		S ();
		if ( c != '@' )
			throw c;
		cout << "SUCCESS !!!" << endl;
		return 0;
		}
	catch ( int c ) {
		cout << "ERROR on lexeme" << c << endl;
		return 1;
		}
	}
