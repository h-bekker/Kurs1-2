#include <iostream>
using namespace std;

char c;
void A();
void gc() { cin >> c; }

void S() {
	A();
	}

void A() {
	if (c == 'a') {
		gc();
		cout << '2';
		A();
		cout << 'a';
		}
	else if (c == 'b') {
			gc();
			A();
			cout << 'b';
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
