#include <iostream>
#include <cmath>
using namespace std;

char c;
int a=0;
void A();
void B();
void gc() { cin >> c; }

void S() {
	if (c == '1') {
		a++;
		gc();
		A();
		}
	else
		throw c;
	}

void A() {
	if (c == '1') {
		a++;
		gc();
		A();
		}
	else if (c == '0') {
			a--;
			gc();
			B();
			}
		else 
			throw c;
	}

void B() {
	if (c == '0') {
		a--;
		gc();
		B();
		}	
	else {
		if (a>0)
			for (int i=0; i<a; i++)
				cout << '1';
		else if (a<0)
				for (int i=0; i<abs(a); i++)
					cout << '0';
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
