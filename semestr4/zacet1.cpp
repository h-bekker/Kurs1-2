#include <iostream>
using namespace std;

class complex {
		int re;
		int im;
		friend class arr;
	public:
		complex(int a=0, int b=0) { re = a; im = b; };
		complex(const complex& c) {re = c.re; im = c.im; };
		void put(int a=0, int b=0) { re = a; im = b; };
		complex get() { return *this; }
		void print() { cout << "re: " << re << " " << "im: " << im << endl; }
		~complex() { };
	};

class arr {
		complex* mas;
		int dim;
	public:
		arr(arr& a);
		arr() { mas = NULL; dim = 0; }
		void push(const complex&);
		~arr() { delete[] mas; }
		complex operator[] (int);
	};

arr:: arr(arr& a) {
	mas = new complex[a.dim];
	dim = a.dim;
	for (int i=0; i<dim; i++) 
		mas[i]=a.mas[i];
	}

void arr:: push(const complex& c) {
	complex* tmp;
	tmp = new complex[dim+1];
	for (int i=0; i<dim; i++)
		tmp[i]=mas[i];
	tmp[dim]=c;
	dim++;
	delete[] mas;
	mas = tmp;
	}

complex arr:: operator[] (int k) {
	if (k % 2 == 0)
		return mas[k];
	else {
		complex c;
		c.re=mas[k].re;
		c.im=-(mas[k].im);
		return c;
		}
	}

int main() {
	int k, r, i;
	complex c;
	arr a;
	cin >> k;
	for (int j=0; j<k; j++) {
		cin >> r >> i;
		c.put(r,i);
		a.push(c);
		}
	cin >> r >> i;
	a[r].print();
	a[i].print();
	}
