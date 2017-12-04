#include <iostream>
using namespace std;

class fridge {
		char* color;
		int len;
		int wid;
		int heig;
	public:
		fridge(char* c="white", int a=7, int b=7, int c) {
			color=new char[strlen(c)+1];
			color=strncpy(color,c,strlen(c));
			color[strlen(c)]='\0';
			len=a;
			wid=b;
			heig=c;
			}
		fridge() {color=NULL;}
		fridge operator++() {
			fridge f;
			f=*this;
			len++;
			wid++;
			heig++;
			return f;
			}
		fridge operator=() {
			fridge f;
			color=new char[strlen(color)+1];
			
			

int main() {
	fridge R("blue",7,1,12);
	fridge G(7);
	fridge Res=R++;
	cout<<Res<<R<<G;
	Res=G+R;
	Res=4+G;
	cout<<Res<<R<<G;
	Res[1]=Res[2]+10;
	cout<<Res<<R<<++G;
	return 0;
	}
