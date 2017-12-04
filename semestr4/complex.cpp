#include <iostream>
using namespace std;

class complex {
		int re;
		int im;
	public:
		void comprint() {cout << re << "+" << im << "i" << endl; }
		void comscan() {cin >> re >> im; }
		friend ostream & operator <<(ostream &, const complex &);
		friend istream & operator >>(istream &, complex &);
		complex() {re=0; im=0; }
		complex(int x, int y) {re=x; im=y; }
		complex(const complex &a) {re=a.re; im=a.im; }
		~complex() { };
		complex operator+(const complex & a) {
			complex tmp(re+a.re, im+a.im);
			return tmp;
			}
		complex operator-(const complex & a) {
			complex tmp(re-a.re, im-a.im);
			return tmp;
			}
		complex operator*(const complex & a) {
			complex tmp(re*a.re-im*a.im, im*a.re+re*a.im);
			return tmp;
			}
		complex & operator++ () {
			re++;
			im++;
			return *this;
			}
		complex operator++ (int) {
			complex c=*this;
			re=re+1;
			im=im+1;
			return c;
			}
		complex operator +=(const complex & a) {re+=a.re; im+=a.im; return *this; }
	};

ostream & operator <<(ostream & s, const complex & a) {
	if (a.re!=0)
		s << a.re;
	if (a.im==1) {
		if (a.re!=0) 
			s << "+";
		s << "i" << endl;
		return s;
		}
	if (a.im==-1) {
		s << "-i" << endl;
		return s;
		}
	if ((a.im>0) && (a.re!=0))
		s << "+";
	if (a.im!=0)
		s << a.im << "i" << endl;
	else
		s << endl;
	return s;
	}	

istream & operator >>(istream & s, complex & a) {
	int x,y;
	s >> x >> y;
	a.re=x;
	a.im=y;
	return s;
	}

int main() {
	complex a,b;
	cin >> a;
	cin >> b;
	complex c;
	cout << a+b;
	cout << a-b;
	cout << a*b;
	c=a++;
	cout << c << a;	
	c+=a;
	cout << c << a;
	c=++a;
	cout << c << a;	
	c+=a;
	cout << c << a;
	return 0;
	}
