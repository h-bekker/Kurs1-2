#include <iostream>
#include <cstring>

using namespace std;

string c;
void S();
void E();
void T();
void gc(){
	cin >> c;
}

void S() {
	if (c=='if'){
		gc();
		E();
		if(c=='then'){
			gc();
			S();
		}
	}
	else (c != 'if'){
		gc();
		E();
	}
}



void E(){
	if (c=='+'){
		gc();
		T();
	}
	else
		if (c !='+'){
			T();
	else
		throw c;
}

void T(){
	if (c=='*'){
		gc();
		F();
	}
	else if (c=='+'){
		gc();
		T();
	}
	else if (c !='*'){
		gc();
		F();
	}
	else
		throw c;
}

void F(){
	if (c=='('){
		gc();
		E();
	}
	else if (c==')'){}
	else P();
}

void P()
int main(){
	try{
		gc();
		S();
		cout << "success" << endl;
		return 0;
	}
	catch (string c){
		cout << "error on lexeme" << c << endl;
		return 1;
	}
}


