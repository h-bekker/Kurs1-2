#include <iostream>
using namespace std;

class A {
    int m;
    friend class B;
public: 
	 A (int n):m(n){}
};
class B {
    int p,q;
    friend class C;
public: 
    B(){p=q=0;}
    B(const A& a){p = a.m; q = a.m;}
};
class C{
    int c1,c2,c3;
public: 
    C(const B& b):c1(b.p),c2(b.q),c3(b.q){}
};

void print(const char *s) {cout<<" 1 "<<s<<endl;}
void print(int d) {cout<<" 2 "<<d<<endl;}
void print(double d) {cout<<"3"<<d<<endl;}
void print1(const A&) {cout<<"Object A"<<endl;}
void print1(const C&,int t) {cout<<"Object C"<<endl;}
void print2(int a, int b) {cout<<"print 2 int"<<endl;}
void print2(double a, double b) {cout<<"print 2 double"<<endl;}
void print2(int a,...) {cout<< "print 2..."<<endl;}

int main() {
    print(12UL);                                                                          
	return 0;
	}
