#include <iostream>
using namespace std;

char c;
void A();
void B();
void C();
void gc() { cin >> c; }

void S() {
	A();
	}

void A() {
	if (c == 'a') {
		gc();
		A();
		cout << 'c';
		}
	else if (c == 'b') {
			gc();
			A();
			}
		else {
			B();
			}
	}

void B() {
	if (c == 'c') {
		cout << 'a';
		gc();
		C();
		}	
	else 
		throw c;
	}

void C() {
	if (c == 'c') {
		cout << 'a';
		gc();
		C();
		}
	}

int main() {
	try {
		gc();
		S();
		if (c != '@') 
			throw c;
		cout << endl;
		return 0;
		}
	catch (char c) {
		cout << "Error!" << endl;
		return 1;
		}
	}			
