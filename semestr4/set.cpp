#include <iostream>
#include <cstring>
using namespace std;

template <class T> 
class Set {
	T *elemSet;
	int count;
public:
	Set() {
		count = 0;
		elemSet = NULL;
	};

	~Set() {
		delete [] elemSet;
	};
	
	Set<T> operator* (Set<T> &);
	Set<T> & operator= (Set<T>);
	Set<T> operator+ (Set<T> &);
	Set<T> operator- (Set<T> &);

	void insertElem(T);
	void deleteElem(T);
	void printSet();
	bool findElem(T);
};

template <class T>
Set<T> Set<T>::operator- (Set<T> & s) {
	Set<T> tmp;

	for (int i = 0; i < count; i++)
		if (!s.findElem(elemSet[i]))
			tmp.insertElem(elemSet[i]);
	return tmp;	
}

template <class T>
Set<T> Set<T>::operator+ (Set<T> & s) {
	Set<T> tmp;

	tmp.count = count + s.count;
	tmp.elemSet = new T [tmp.count];
	memcpy(tmp.elemSet, elemSet, count * sizeof(T));
	memcpy(tmp.elemSet + count, s.elemSet, s.count * sizeof(T));
	return tmp;
}

template <class T>
Set<T> & Set<T>::operator= (Set<T> s) {//why????
	elemSet = new T [s.count];
	memcpy(elemSet, s.elemSet, s.count * sizeof(T));
	count = s.count;
	return *this;
}

template <class T>
Set<T> Set<T>::operator* (Set<T> & s) {
	Set<T> tmp;

	for (int i = 0; i < count; i++)
		if (s.findElem(elemSet[i])) {
			tmp.insertElem(elemSet[i]);
		}
	return tmp;	
}

template <class T>
void Set<T>::deleteElem(T elem) {
	T *tmp;

	for (int i = 0; i < count; i++)
		if (elem == elemSet[i]) {
			for (int j = i; j < count - 1; j++)
				elemSet[j] = elemSet[j + 1];
			tmp = new T [count - 1];
			memcpy(tmp, elemSet, (count - 1) * sizeof(T));
			elemSet = new T [count - 1];
			memcpy(elemSet, tmp, (count - 1) * sizeof(T));
			delete [] tmp;
			count--;
			i--;
		}
}

template <class T>
void Set<T>::printSet() {
	for (int i = 0; i < count; i++)
		cout << elemSet[i] << ' ';
	cout << endl;
};

template <class T>
void Set<T>::insertElem(T elem) {
	T *tmp;

	if (elemSet == NULL)
		elemSet = new T [1];
	else {
		tmp = new T [count];
		memcpy(tmp, elemSet, count * sizeof(T));
		elemSet = new T [count + 1];
		memcpy(elemSet, tmp, count * sizeof(T));
		delete [] tmp;
	}
	elemSet[count] = elem;
	count++;
}

template <class T>
bool Set<T>::findElem(T elem) {
	for (int i = 0; i < count; i++)
		if (elem == elemSet[i])
			return true;
	return false;	
}

int main(void) {
	Set<int> s1;
	Set<int> s2;
	Set<char*> s3;
	Set<char*> s4;

	s1.insertElem(1);
	s2.insertElem(2);
	s3.insertElem("abc");
	s4.insertElem("qwe");
	(s1 + s2).printSet();
	(s3 + s4).printSet();
	return 0;
}