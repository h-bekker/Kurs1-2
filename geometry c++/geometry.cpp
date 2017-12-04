#include <iostream>
#include <algorithm>
using namespace std;

struct point {
	int x,y;
};

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

int main() 
{
	int S;
	point A,B,C;
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
	S=cross(A-C,B-C);
	cout << abs(S)/2.0 << endl;
}