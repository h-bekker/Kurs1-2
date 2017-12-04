#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Wordcard {
		char* engword;
		char* translate;
		int rating;
		Wordcard() {engword=NULL; translate=NULL; rating=0; } //поменять
		Wordcard(const char*, const char*, int);
		Wordcard(const Wordcard &);
		Wordcard operator=(const Wordcard &);
		virtual ~Wordcard() {if (engword!=NULL) delete [] engword; if (translate!=NULL) delete [] translate; }
		friend bool operator==(const Wordcard &, const Wordcard &);
		friend istream & operator >>(istream &, Wordcard &);
		virtual void chgrate(int k) {rating=k; }
		virtual void print() const;
	};

struct Verb : public Wordcard {
		int regular;
		Verb() {engword=NULL; translate=NULL; rating=0; regular=0; }
		Verb(const char*, const char*, int, int);
		Verb(const Verb &);
		Verb operator=(const Verb &);
		~Verb() {}//{if (engword!=NULL) delete [] engword; if (translate!=NULL) delete [] translate; }
		void chgrate(int k) {rating=k; }
		void print() const;
		};	
		
struct Noun : public Wordcard {
		int gender;
		Noun() {engword=NULL; translate=NULL; rating=0; gender=0; }
		Noun(const char*, const char*, int, int);
		Noun(const Noun &);
		Noun operator=(const Noun &);
		~Noun() {}//{if (engword!=NULL) delete [] engword; if (translate!=NULL) delete [] translate; }
		void chgrate(int k) {rating=k; }
		void print() const;
		};

Wordcard:: Wordcard(const char* s1, const char* s2, int k) {
	engword=new char[strlen(s1)+1]; // выделяем память
	engword=strncpy(engword,s1,strlen(s1)+1); // копируем
	translate=new char[strlen(s2)+1];
	translate=strncpy(translate,s2,strlen(s2)+1);
	rating=k;
	}

Verb:: Verb(const char* s1, const char* s2, int rate, int reg) {
	engword=new char[strlen(s1)+1]; // выделяем память
	engword=strncpy(engword,s1,strlen(s1)+1); // копируем
	translate=new char[strlen(s2)+1];
	translate=strncpy(translate,s2,strlen(s2)+1);
	rating=rate;
	regular=reg;	
	}

Noun:: Noun(const char* s1, const char* s2, int rate, int gen) {
	engword=new char[strlen(s1)+1]; // выделяем память
	engword=strncpy(engword,s1,strlen(s1)+1); // копируем
	translate=new char[strlen(s2)+1];
	translate=strncpy(translate,s2,strlen(s2)+1);
	rating=rate;
	gender=gen;
	}

Wordcard:: Wordcard(const Wordcard& w) {
	engword=new char[strlen(w.engword)+1]; //выделяем память
	engword=strncpy(engword,w.engword,strlen(w.engword)+1); // копируем
	translate=new char[strlen(w.translate)+1];
	translate=strncpy(translate,w.translate,strlen(w.translate)+1);
	rating=w.rating;
	}

Verb:: Verb(const Verb& v) {
	engword=new char[strlen(v.engword)+1]; //выделяем память
	engword=strncpy(engword,v.engword,strlen(v.engword)+1); // копируем
	translate=new char[strlen(v.translate)+1];
	translate=strncpy(translate,v.translate,strlen(v.translate)+1);
	rating=v.rating;
	regular=v.regular;
	}

Noun:: Noun(const Noun& n) {
	engword=new char[strlen(n.engword)+1]; //выделяем память
	engword=strncpy(engword,n.engword,strlen(n.engword)+1); // копируем
	translate=new char[strlen(n.translate)+1];
	translate=strncpy(translate,n.translate,strlen(n.translate)+1);
	rating=n.rating;
	gender=n.gender;
	}

Wordcard Wordcard:: operator=(const Wordcard & w) {
	if (engword!=NULL)
		delete[] engword;
	if (translate!=NULL)
		delete[] translate;
	engword=new char[strlen(w.engword)+1];
	engword=strncpy(engword,w.engword,strlen(w.engword)+1);
	translate=new char[strlen(w.translate)+1];
	translate=strncpy(translate,w.translate,strlen(w.translate)+1);
	rating=w.rating;
	return *this;
	}					

Verb Verb:: operator=(const Verb & v) {
	if (engword!=NULL)
		delete[] engword;
	if (translate!=NULL)
		delete[] translate;
	engword=new char[strlen(v.engword)+1];
	engword=strncpy(engword,v.engword,strlen(v.engword)+1);
	translate=new char[strlen(v.translate)+1];
	translate=strncpy(translate,v.translate,strlen(v.translate)+1);
	rating=v.rating;
	regular=v.regular;
	return *this;
	}	

Noun Noun:: operator=(const Noun & n) {
	if (engword!=NULL)
		delete[] engword;
	if (translate!=NULL)
		delete[] translate;
	engword=new char[strlen(n.engword)+1];
	engword=strncpy(engword,n.engword,strlen(n.engword)+1);
	translate=new char[strlen(n.translate)+1];
	translate=strncpy(translate,n.translate,strlen(n.translate)+1);
	rating=n.rating;
	gender=n.gender;
	return *this;
	}

bool operator==(const Wordcard & w1, const Wordcard & w2) {
	if ((strncmp(w1.engword,w2.engword,strlen(w1.engword)+1)==0) && (strncmp(w1.translate,w2.translate,strlen(w1.translate)+1)==0))
		return true;
	return false;
	}

void Wordcard :: print() const {
	cout << endl << engword << " - " << translate << " - " << rating;
	}

void Verb :: print() const {
	Wordcard :: print();
	cout << ". Type of regular: " << regular;
	}

void Noun :: print() const {
	Wordcard :: print();
	cout << ". Type of gender: " << gender;
	}	 

class Dictionary {
		char* name;
		Wordcard** arr;
		int size;
	public:
		Dictionary(char* n=(char*)"Eng-rus") {name=new char[strlen(n)+1]; name=strncpy(name,n,strlen(n)+1); arr=NULL; size=0;} //создаем словарь
		char* get_name() {return name; } 
		int get_size() {return size; }
		void chgname(char* n) {delete [] name; name=new char[strlen(n)+1]; name=strncpy(name,n,strlen(n)+1); } //меняем название словаря
		Wordcard** new1(int, int); //выделяем память для новой карточки
		void pushword (Wordcard*); //добавляем карточку
		void delword(Wordcard*); //удаляем карточку
		bool search(Wordcard*); //поиск слова (и на русском, и на английском)
		void clear(); //очистка от копии
		char* operator [](char*);
		Dictionary operator=(const Dictionary &);
		//void print() {cout << arr[0]->engword << endl; }
		friend ostream & operator <<(ostream &, const Dictionary &);
		~Dictionary() {delete[] name; if (!arr) delete[] arr;}
		friend Dictionary operator+(const Dictionary &, const Dictionary &);
		friend Dictionary operator-(const Dictionary &, const Dictionary &);
		void print();
	};				

Wordcard** Dictionary:: new1(int r1, int r2) {
	Wordcard** tmp;
	tmp=new Wordcard*[r2];
	for (int i=0; i<r1; i++) { // перекопирование в новый кусок памяти
		tmp[i]=arr[i];
		}
	size=r2;
	arr=tmp;
	return arr;
	}

void Dictionary:: pushword(Wordcard *w) {
	//cout << size << endl;
	arr=new1(size,size+1); //выделяем память
	arr[size-1]=w;
	}

void Dictionary:: delword(Wordcard *w) {
	for (int i=0; i<size; i++)
		if (*arr[i]==*w) { // поиск карточки
			for (int j=i; j<size-1; j++) {
				arr[j]=arr[j+1]; 
				}
			size--;
		}
	}

bool Dictionary:: search(Wordcard *w) {
	for (int i=0; i<size; i++) {
		if (strncmp(arr[i]->engword,w->engword,strlen(w->engword)+1)==0) //если совпадают слова на английском
			return true;
		if (strncmp(arr[i]->translate,w->translate,strlen(w->translate)+1)==0) //если совпадают слова на русском
			return true;
		}
	return false;
	}

void Dictionary:: clear() {
	for (int i=0; i<size; i++)
		for (int j=i; j<size; j++)
			if ((i!=j) && (*(arr[i])==*(arr[j]))) { //если есть копия
				cout << i << " " << j << endl;
				//cout << *this << endl;
				for (int k=j; k<size-1; k++)
					arr[k]=arr[k+1];
				size--;
				//cout << *this << endl;
			}
	}

char* Dictionary:: operator[](char* word) {
	for (int i=0; i<size; i++) {
		if (strncmp(arr[i]->engword,word,strlen(word)+1)==0)
			return arr[i]->translate;
		}
	return NULL;
	}

Dictionary Dictionary:: operator=(const Dictionary & d) {
	if (arr!=NULL)
		delete[] arr;
	size=d.size;
	arr=new Wordcard*[size];
	for (int i=0; i<size; i++)
		*arr[i]=*d.arr[i];
	return *this;
	}	

ostream & operator <<(ostream & st, const Dictionary & d) {
	for (int i=0; i<d.size; i++) {
		st << d.arr[i]->engword << "-" << d.arr[i]->translate << "-" << d.arr[i]->rating << endl;
		}
	return st;
	}

Dictionary operator+(const Dictionary & d1, const Dictionary & d2) {
	Dictionary dans;
//	d1.chgname("Dic1");
//	d2.chgname("Dic2");
	for (int i=0; i<d1.size; i++)
		dans.pushword(d1.arr[i]);
	for (int i=0; i<d2.size; i++)
		dans.pushword(d2.arr[i]);
	return dans;	
	}

Dictionary operator-(const Dictionary & d1, const Dictionary & d2) {
	Dictionary dans;
	bool flag;
//	d1.chgname("Dic1");
//	d2.chgname("Dic2");
	for (int i=0; i<d1.size; i++) {
		flag=true;
		for (int j=0; j<d2.size; j++)
			if (*d1.arr[i]==*d2.arr[j]) {
				flag=false;
				break;
				}
		if (flag)
			dans.pushword(d1.arr[i]);
		}
	return dans;	
	}

void Dictionary :: print() {
	for (int i=0; i<get_size(); i++) 
		arr[i]->print();
	cout << endl;
	}

bool readline(ifstream & f, Wordcard& w, Verb& v, Noun& n) {
	char *temp1, *temp2;
	temp1=new char[60];
	if (!(f >> temp1)) {
		delete[] temp1;
		return false;
		}
	temp1[strlen(temp1)]='\0';
	temp2=new char[60];
	if (!(f >> temp2)) return false;
	temp2[strlen(temp2)]='\0';
	int k;
	f >> k;
	if (k==0) {
		w.engword=new char[strlen(temp1)+1];
		w.engword=strncpy(w.engword,temp1,strlen(temp1)+1);
		w.translate=new char[strlen(temp2)+1];
		w.translate=strncpy(w.translate,temp2,strlen(temp2)+1);
		f >> k;
		}
	else {
		if (k==1) {
			v.engword=new char[strlen(temp1)+1];
			v.engword=strncpy(v.engword,temp1,strlen(temp1)+1);
			v.translate=new char[strlen(temp2)+1];
			v.translate=strncpy(v.translate,temp2,strlen(temp2)+1);
			f >> k;
			v.regular=k;
			}
		else {
			n.engword=new char[strlen(temp1)+1];
			n.engword=strncpy(n.engword,temp1,strlen(temp1)+1);
			n.translate=new char[strlen(temp2)+1];
			n.translate=strncpy(n.translate,temp2,strlen(temp2)+1);
			f >> k;
			n.gender=k;
			}
		}		
	cout << temp1 << " " << temp2 << endl;
	delete [] temp1; //очищаем буфер
	delete [] temp2;	
	return true;
	} 

int main() {
	Dictionary d;
	cout << d.get_name() << endl;
	ifstream f;
	f.open("dic2.txt");
	//Wordcard w[100];
	Wordcard* w;
	Verb* v;
	Noun* n;
	w=new Wordcard[1];
	v=new Verb[1];
	n=new Noun[1];
	while (readline(f,w[0],v[0],n[0])) {//(f >> w)
		if (w[0].engword!=NULL)
			d.pushword(&w[0]);
		if (v[0].engword!=NULL)
			d.pushword(&v[0]);
		if (n[0].engword!=NULL)
			d.pushword(&n[0]);
		//d.print();
		if (w[0].engword!=NULL)
			w=new Wordcard[1];
		if (v[0].engword!=NULL) 
			v=new Verb[1];
		if (n[0].engword!=NULL)
			n=new Noun[1];
		//cout << d;
		//cout << "noun " << n.engword << endl;
		}
	//cout << d;
	d.print();
	Wordcard u("tea","чай",0);
	bool flag=d.search(&u);
	cout << flag << endl;
	d.delword(&u);
	//cout << d;
	d.print();
	flag=d.search(&u);
	cout << flag << endl;
	cout << d["human"] << endl;	
	cout << d+d;
	cout << d-d;
	return 0;
	}
