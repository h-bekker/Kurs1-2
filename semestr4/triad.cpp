#include <iostream>
using namespace std;

int month[]={31,28,31,30,31,30,31,31,30,31,30,31};

class newexcept1 : public exception {
	public:
		newexcept1() throw() { }
		~newexcept1() throw() { }
	};

class newexcept2 : public exception {
	public:
		newexcept2() throw() { }
		~newexcept2() throw() { }
	};

class triad {
	public:
		int a;
		int b;
		int c;
	public:
		virtual triad & operator+(const triad &)=0;
		virtual triad & operator-(const triad &)=0;
	};

class Time : public triad {
	public:
		Time(int x=0, int y=0, int z=0) {a=x; b=y; c=z; };
		Time(const Time &t) {a=t.a; b=t.b; c=t.c; };
		~Time() {};
		Time & scan();
		void print();
		Time & operator+(const triad &t);
		Time & operator-(const triad &t);
		};

class date : public triad {
	public:
		date(int x=1970, int y=1, int z=1) {a=x; b=y; c=z; };
		date(const date &d) {a=d.a; b=d.b; c=d.c; };
		~date() {};
		date & scan();
		void print();
		date & operator+(const triad &d);
		date & operator-(const triad &d);
		date & operator=(const triad &d) { a=d.a; b=d.b; c=d.c; return *this; };
		};

Time & Time::scan() {
	char c1,c2;
	cin >> a >> c1 >> b >> c2 >> c;
	if ((c1!=':') || (c2!=':')) {
		newexcept2 e;
		throw e;
		}
	return *this;
	};

void Time:: print() {
	cout << a << ":" << b << ":" << c << endl;
	};

Time & Time:: operator+(const triad &t) {
	bool flag=false;
	if (c+t.c>=60)
		flag=true;
	c=(c+t.c) % 60; //секунды
	int k=(b+t.b+(int)flag) % 60;
	if ((b+t.b+(int)flag)>=60) 
		flag=true;
	else
		flag=false;
	b=k; //минуты
	a=(a+t.a+(int)flag) % 24;//часы
	return *this;
	};

Time & Time:: operator-(const triad &t) {

	int fir=c;
	fir+=b*60;
	fir+=a*3600;
	int sec=t.c;
	sec+=t.b*60;
	sec+=t.a*3600;
	if (fir<sec) {
		newexcept1 e;
		throw e;
		}
//throw();
	else
		fir-=sec;
	sec=fir / 3600;
	a=sec;
	fir-=sec*3600;
	sec=fir / 60;
	b=sec;
	fir-=sec*60;
	c=fir;
	return *this;
	};

date & date::scan() {
	char c1,c2;
	cin >> a >> c1 >> b >> c2 >> c;
	if ((c1!='.') || (c2!='.')) {
		newexcept2 e;
		throw e;
		}
	return *this;
	};

void date:: print() {
	cout << a << "." << b << "." << c << endl;
	};

date & date:: operator+(const triad &d) {
	long long int d1=0;
	for (int i=0; i<b-1; i++) 
		d1+=month[i];
	d1+=c;
	for (int i=0; i<d.b-1; i++)
		d1+=month[i];
	d1+=d.c;
	a+=d.a;
	if (d1>365)
		a++;
	if ((d1 % 365) != 0)
		d1=d1 % 365;
	else
		d1=365;
	b=0;
	for (int i=0; i<12; i++) {
		if (month[i]<d1) {
			b++;
			d1-=month[i];
			}
		else {
			b++;
			c=d1;
			break;
			}
		}
	return *this;
	};

date & date:: operator-(const triad &d) {
	long long int d1=0, d2=0;
	for (int i=0; i<b-1; i++) 
		d1+=month[i];
	d1+=c;
	for (int i=0; i<d.b-1; i++)
		d2+=month[i];
	d2+=d.c;
	if ((a<d.a) || ((a==d.a) && (d1<d2))) {
		newexcept1 e;
		throw e;					
		}
	if (d1<d2) {
		a--;
		d1+=365;
		}
	a-=d.a;
	d1-=d2;
	b=0;
	for (int i=0; i<12; i++) {
		if (month[i]<d1) {
			b++;
			d1-=month[i];
			}
		else {
			b++;
			c=d1;
			break;
			}
		}
	return *this;
	};
	


int main(void) {
	try {
		//Time t1,t2;
		//t1.scan();
		//t2.scan();
		//t1-t2;
		//t1.print();
		date d1,d2;
		d1.scan();
		d2.scan();
		date d3=d1;
		d1+d2;
		d1.print();
		d3-d2;
		d3.print();
		return 0;
		}
	catch(newexcept1) { cout << "First time/date low" << endl; }
	catch(newexcept2) { cout << "Wrong input" << endl; }
	catch(...) { cout << "Error is not good" << endl; }
	}
