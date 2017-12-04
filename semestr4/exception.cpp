#include <iostream>
#include <cstring>
using namespace std;
enum {SIZE=256};
class except {
	public:
		except() throw() { cout << "Constructor Except" << endl; }
		except(const except &) throw() { cout << "Constructor Except copy" << endl; }
		virtual ~except() throw() { cout << "Destructor Except" << endl; }
	};

class NullExcept: public except {
	public:
		NullExcept() throw() { cout << "Constructor Null Except" << endl; }
		~NullExcept() throw() { cout << "Destructor Null Except" << endl; }
	};

class OutOfRan: public except {
	public:
		OutOfRan() throw() { cout << "Constructor Out of Range" << endl; }
		~OutOfRan() throw() { cout << "Destructor Out of Range" << endl; }
	};


class IllegNum: public except {
	public:
		IllegNum() throw() { cout << "Constructor Illeg Num" << endl; }
		~IllegNum() throw() { cout << "Destructor Illeg Num" << endl; }
	};

int main(void) {
	try {
		NullExcept e1;
		OutOfRan e2;
		IllegNum e3;
		char *str, c;
		str=new char[SIZE];
		for (int i=0; i<SIZE; i++) {
			cin >> c;
			if (c!='$') {
				if (((c>='0') && (c<='9')) || ((c>='A') && (c<='F'))) {
					if (!((c=='0') && (i==0)))
						str[i]=c;
					else
						throw e3;
					}
				else
					throw e3;
				}
			else
				break;
			};
		if (strlen(str)>16)
			throw e2;
		long long int ans=0;
		long long int k;
		for (int i=0; i<strlen(str); i++) {
			if ((str[i]>='0') && (str[i]<='9'))
				k=str[i]-'0';
			else
				k=str[i]-'A'+10;
			for (int j=0; j<strlen(str)-i-1; j++)
				k*=16;
			ans+=k;
			}
		if (!strlen(str))
			throw e1;
		cout << ans << endl;
		}
	catch(NullExcept) { cout << "String is null" << endl;}
	catch(OutOfRan) { cout << "Big Number" << endl;}
	catch(IllegNum) { cout << "Wrong Input" << endl;}
	}
				
			
