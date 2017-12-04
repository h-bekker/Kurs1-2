#include <iostream>
using namespace std;

template < class T > 
T sum ( T array[ ], int size ) {
	T res = 0;
	for ( int i = 0; i < size; i++ ) res += array[ i ];
	return res;
}

int main() {
	int ans=0;
	int *arr;	
	arr=new int[10];
	for (int i=0; i<10; i++)
		cin >> arr[i];
	ans=sum <int> (arr,10);
	cout << ans << endl;
	}
