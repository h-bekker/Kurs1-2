#include <iostream>
using namespace std;

char c;
void A();
void gc() { cin >> c; }

void S() {
	if (c == 'a') {
		gc();
		if (c == 'b') {
			cout << 'b';
			gc();
			A();
			}
		else
			throw c;
		}
	else if (c == 'b') {
			gc();
			if (c == 'a') {
				cout << 'a';
				gc();
				A();
				}
			else 
				throw c;
			}
		else
			throw c;
	}

void A() {
	if (c == 'a') {
		gc();
		if (c == 'b') {
			cout << 'b';
			gc();
			A();
			}
		else
			throw c;
		}
	else if (c == 'b') {
			gc();
			if (c == 'a') {
				cout << 'a';
				gc();
				A();
				}
			else 
				throw c;
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
