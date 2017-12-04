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
	point A,B,C,D;
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
	int S1=cross(A-C,B-C);
	if ((S1*cross(A-D,B-D)>=0) && (S1*cross(B-D,C-D)>=0) && (S1*cross(C-D,A-D)>=0))
		cout << "In" << endl;
	else
		cout << "Out" << endl;
}
