#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

struct Wordcard {
		char* engword;
		char* translate;
		int rating;
		Wordcard() {engword=NULL; translate=NULL; rating=0; }
		Wordcard(char*, char*, int);
		Wordcard(const Wordcard &);
		~Wordcard() {delete [] engword; delete [] translate; }
		friend istream & operator >>(istream &, Wordcard &);
		//friend void Dictionary::chgrate(const Wordcard &);
	};

Wordcard:: Wordcard(char* s1, char* s2, int k) {
	engword=new char[strlen(s1)+1];
	engword=strncpy(engword,s1,strlen(s1));
	engword[strlen(s1)]='\0';
	translate=new char[strlen(s2)+1];
	translate=strncpy(translate,s2,strlen(s2));
	translate[strlen(s2)]='\0';
	rating=k;
	}

Wordcard:: Wordcard(const Wordcard& w) {
	engword=new char[strlen(w.engword)+1];
	engword=strncpy(engword,w.engword,strlen(w.engword));
	engword[strlen(w.engword)]='\0';
	translate=new char[strlen(w.translate)+1];
	translate=strncpy(translate,w.translate,strlen(w.translate));
	translate[strlen(w.translate)]='\0';
	rating=w.rating;
	}

istream & operator >>(istream & st, Wordcard & w) {
	char* temp;
	temp=new char[20];
	st >> temp;
	w.engword=new char[strlen(temp)+1];
	w.engword=strncpy(w.engword,temp,strlen(temp)+1);
	cout << temp << " ";
	delete [] temp;
	temp=new char[20];
	st >> temp;
	w.translate=new char[strlen(temp)+1];
	w.translate=strncpy(w.translate,temp,strlen(temp)+1);
	cout << temp << endl;
	delete [] temp;
	return st;
	}

class Dictionary {
		char* name;
		vector <Wordcard> arr;
	public:
		Dictionary(char* n=(char*)"Eng-rus") {name=new char[strlen(n)+1]; name=strncpy(name,n,strlen(n)); name[strlen(n)]='\0'; }
		char* get_name() {return name; }
		void chgname(char* n) {delete [] name; name=new char[strlen(n)+1]; name=strncpy(name,n,strlen(n)); name[strlen(n)]='\0'; }
		void pushword(Wordcard w) {arr.push_back(w); }
		void delword(Wordcard);
		bool search(Wordcard);
		friend ostream & operator <<(ostream &, const Dictionary &);
		//friend Dictionary operator+(const Dictionary &, const Dictionary &) {}
		//friend Dictionary operator-(const Dictionary &, const Dictionary &) {}
		void chgrate(const Wordcard &) {}
	};

void Dictionary:: delword(Wordcard w) {
	cout << arr.size();
	vector <Wordcard> :: iterator it=arr.begin();	
	while (it!=arr.end()) {
		cout << (*it).engword << "-" << (*it).translate << "-" << (*it).rating << endl;
		if ((strncmp((*it).engword,w.engword,strlen(w.engword))==0) && (strncmp((*it).translate,w.translate,strlen(w.translate))==0)) {
			it=arr.erase(it);
			continue;
			}
		it++;
		}
	cout << arr.size();
	}

bool Dictionary:: search(Wordcard w) {
	vector <Wordcard> :: const_iterator it=arr.begin();
	while (it!=arr.end()) {
		if (strncmp((*it).engword,w.engword,strlen(w.engword))==0)
			return true;
		if (strncmp((*it).translate,w.translate,strlen(w.translate))==0)
			return true;
		it++;
		}
	return false;
	}

ostream & operator <<(ostream & st, const Dictionary & d) {
	vector <Wordcard> :: const_iterator it=d.arr.begin();
	while (it!=d.arr.end()) {	
		st << (*it).engword << "-" << (*it).translate << "-" << (*it).rating << endl;
		it++;
		}
	return st;
	}

int main() {
	//Dictionary d;
	//cout << d.get_name() << endl;
	//Wordcard w,u;
	ifstream f;
	string a;
	//c=new char[20];
	f.open("dic.txt");
	//f >> u;
	//d.pushword(u);
	int k=0;
	while(f >> a) {
		k++;
		cout << a;
		//d.pushword(w);
		//считывает на один больше чем надо	
		}
	//cout << k << endl;
	//d.delword(w);
	//d.delword(u);
	//cout << d;
	//f.close();
	}
