#include <iostream>
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

/*point operator+(point A,point B) {
	point C;
	C.x=A.x+B.x;
	C.y=A.y+B.y;
	return C;
}
*/
point operator-(point A,point B) {
	point C;
	C.x=A.x-B.x;
	C.y=A.y-B.y;
	return C;
}

int main() 
{
	point A,B,C,D;
	cin >> A.x >> A.y >> C.x >> C.y >> B.x >> B.y >> D.x >> D.y;
	int S1=cross(A-B,C-B);
	int S2=cross(A-D,C-D);
	int S3=cross(D-A,B-A);
	int S4=cross(D-C,B-C);
	int D1=dot(A-B,C-B);
	int D2=dot(A-D,C-D); 
	int D3=dot(D-A,B-A);
	int D4=dot(D-C,B-C);
	if (((S1==0) && (D1<=0)) || ((S2==0) && (D2<=0)) || ((S3==0) && (D3<=0)) || ((S4==0) && (D4<=0)) || ((S1*S2<=0) && (S3*S4<=0)))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
