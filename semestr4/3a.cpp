#include <iostream>

using namespace std;

char c;
void A();
void B();
void D();
void gc(){
	cin >> c;
}

void S() {
	if (c=='b'){
		gc();
		S();
	}
	else if (c=='a'){
		gc();
		A();
	}
	else if (c != '@')
		throw c;
}



void A(){
	if (c=='c'){
		gc();
		B();
	}
	else
		if (c=='b'){
			gc();
			if (c=='c'){
				gc();
				A();
			}
			else{
				throw c;
			}
		}
	else
		throw c;
}

void B(){
	if (c=='c'){
		gc();
		A();
	}
	else if (c=='b'){
		gc();
		D();
	}
	else
		throw c;
}

void D(){
	if (c=='c'){
		gc();
		if (c=='b'){
			gc();
			D();
		}
		else
			throw c;
	}
	else if (c=='@'){
	}
	else{
		throw c;
	}
}

int main(){
	try{
		gc();
		S();
		cout << "success" << endl;
		return 0;
	}
	catch (char c){
		cout << "error on lexeme" << c << endl;
		return 1;
	}
}


