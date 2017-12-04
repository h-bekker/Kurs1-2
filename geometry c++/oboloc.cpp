#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

struct point {
	int x,y;
};

stack <int> s;
point v[20005],u[20005];


int dot(point A,point B) {
	return A.x*B.x+A.y*B.y;
}

int cross(point A,point B) {
	return A.x*B.y-A.y*B.x;
}

point operator+(point A,point B) {
	point C;
	C.x=A.x+B.x;
	C.y=A.y+B.y;
	return C;
}

point operator-(point A,point B) {
	point C;
	C.x=A.x-B.x;
	C.y=A.y-B.y;
	return C;
}

int sor(int a, int b, int c) {
	return cross(v[a]-v[c],v[b]-v[c]);
}	

int cmp(point A,point B) {
	if (cross(A,B)<0)
		return 1;
	return 0;
}

int main() 
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> v[i].x >> v[i].y;
	int m=0;
	for (int i=0; i<n; i++) {
		while (m>1 && sor(i, m-1, m-2)<0) {
			u[m].x=0;
			u[m].y=0;	
			s.pop();
			m--;
			}
		u[i].x=v[i].x;
		u[i].y=v[i].y;
		s.push(i);
		m++;
	}
	for (int i=n-1; i>=0; i--) {
		while (sor(i,m-1,m-2)>0) {
			u[m].x=0;
			u[m].y=0;	
			s.pop();
			m--;
		}
		u[i].x=v[i].x;
		u[i].y=v[i].y;
		s.push(i);
		m++;
	}
	int sum=0, per=0;
	u[m].x=u[0].x;
	u[m].y=u[0].y;
	for (int i=0; i<m; i++) {
		sum+=cross(u[i],u[i+1]);
		cout << u[i].x << " " << u[i].y << endl;
		cout << sum << endl;
		}		
	cout << sum/2.0 << endl;		
	cout << m << endl;
}
