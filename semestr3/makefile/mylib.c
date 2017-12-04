#include <stdio.h>

#define eps 0.00001

double f(double x, double c, double d) {
	return ((x*x+2*c*x+c*c)+d);
	}

double df(double x, double c, double d) {
	return (2*x+2*c);
	}

double mdl(double x) {
	if (x>=0)
		return x;
	else
		return -x;
	}

double twain(double l, double r, double a, double b) {
	double x;
	while (mdl(l-r)>2*eps) {
		x=(l+r)/2;
		if (f(l,a,b)*f(x,a,b)<0)
			r=x;
		else
			//if (f(r,a,b)*f(x,a,b)<0)
				l=x;
		}
	x=(l+r)/2;
	return x;
	}

double xord(double l, double r, double a, double b) {
	while (mdl(l-r)>eps) {
		l=r-(r-l)*f(r,a,b)/(f(r,a,b)-f(l,a,b));
		r=l+(l-r)*f(l,a,b)/(f(l,a,b)-f(r,a,b));
		}
	return r;
	}

double kass(double l, double r, double a, double b) {
	while (mdl(l-r)>eps) {
		l=r;
		r=r-f(r,a,b)/df(r,a,b);
		}
	return r;
	}

double rectang(int a, int b, int p, int q) {
	int i, n=10;
	double i1=0, i2=0, h;
	do {
		i1=i2;
		h=(b-a)/n;
		i2=0;
		n*=2;
		for (i=0; i<n; i++) {
			printf("%f ",f(a+h*(i+0.5),p,q));
			i2+=f(a+h*(i+0.5),p,q);
			}
		//i2=i2*h;
		//n=n*2;
	}while (mdl(i1-i2)>eps);
	return i2;
	}

/*int main(void) {
	double ans1,ans2,ans3,s,p,q;
	scanf("%lf%lf",&p,&q);
	ans1=twain(0,5,p,q);
	ans2=xord(0,5,p,q);
	ans3=kass(0,5,p,q);
	//s=rectang(-ans1,ans1,p,q);
	printf("%lf %lf %lf\n%lf\n",ans1,ans2,ans3,s);
	}*/
	
