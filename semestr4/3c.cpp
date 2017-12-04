#include <iostream>

using namespace std;

char c;
void A();
void B();
void C();
void D();
void E();
void gc(){
	cin >> c;
}

void S() {
	if (c=='f'){
		gc();
		A();
		gc();
		if (c=='c'){
			gc();
			C();
		}
		else throw c;
	}
	else if (c != '@')
		throw c;
}

void A(){
	if (c=='a'){
		gc();
		B();
	}
	else
		if (c=='d'){}
	else
		throw c;
}

void C(){
	if (c=='a'){
		gc();
		C();
	}
	else if (c=='b'){
			gc();
			if (c=='b'){
				gc();
				C();
			}
			else throw c;
	}
	else if (c=='@'){
		return;
	}
	else throw c;
}

void B(){
	if (c=='a'){
		gc();
		if (c=='b'){
			gc();
			B();
		}
		else throw c;
	}
	else if (c=='f'){
		gc();
		A();
		gc();
		if (c=='c'){
			gc();
			D();
		}
		else throw c;
	}
	else
		throw c;
}

void D(){
	if (c=='a'){
		gc();
		D();
	}
	else if (c=='b'){
			gc();
			E();
		}
	else throw c;
}

void E(){
	if (c=='b'){
		gc();
		D();
	}
	else if (c=='@'){}
	else throw c;
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


