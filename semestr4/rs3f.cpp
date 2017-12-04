#include <iostream>
using namespace std;

int c;
void S1 ();
void P ();
void P1 ();
void E ();
void T ();
void F ();
void I ();
void gc () {
	cin >> c;
	}
// текущий анализируемый символ
// считать очередной символ
void S () {
	if (c == 'i') {
		cout << "S-->if E then S S1\n";
		gc();
		if (c == 'f') {
			E();
			gc();
			if (c == 't') {
				gc();
				if (c == 'h') {
					gc();
					if (c == 'e') {
						gc();
						if (c == 'n') {
							S();
							gc();
							S1();
							}
						else throw c;
						}
					else throw c;
					}
				else throw c;
				}
			else throw c;
			}
		else throw c;
		}
	else {
		P();
		gc();
		if (c == ':') {
			gc();
			if (c == '=') {
				E();
				}
			else throw c;
			}
		else throw c;
		}
	}

void P () {
	cout << "IP1\n";
	I();
	P1();
	}

void S1 () {
	if (c == 'e') {
		gc();
		if (c == 'l') {
			gc();
			if (c == 's') {
				gc();
				if (c == 'e') {
					gc();
					S();
					}
				else throw c;
				}
			else throw c;
			}
		else throw c;
		}
	}

void P1 () {
	
void E () {
	T();
	
void T () {
	F();

void F () {
	P();

void I () {
	if ((c != 'a') && (c != 'b')) throw c;
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
