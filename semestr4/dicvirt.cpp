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
	};

struct Verb : public Wordcard {
		int regular;
		Verb() {engword=NULL; translate=NULL; rating=0; regular=0; }
		Verb(const char*, const char*, int, int);
		Verb(const Verb &);
		Verb operator=(const Verb &);
		~Verb() {}//{if (engword!=NULL) delete [] engword; if (translate!=NULL) delete [] translate; }
		void chgrate(int k) {rating=k; }
		};	
		
struct Noun : public Wordcard {
		int gender;
		Noun() {engword=NULL; translate=NULL; rating=0; gender=0; }
		Noun(const char*, const char*, int, int);
		Noun(const Noun &);
		Noun operator=(const Noun &);
		~Noun() {}//{if (engword!=NULL) delete [] engword; if (translate!=NULL) delete [] translate; }
		void chgrate(int k) {rating=k; } 
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

/*istream & operator >>(istream & st, Wordcard & w) {
	char* temp;
	temp=new char[60];
	st >> temp; // считывание в буфер
	temp[strlen(temp)]='\0';
	w.engword=new char[strlen(temp)+1];
	w.engword=strncpy(w.engword,temp,strlen(temp)+1);
	//cout << temp << " ";
	st >> temp;
	//temp[strlen(temp)]='\0';
	w.translate=new char[strlen(temp)+1];
	w.translate=strncpy(w.translate,temp,strlen(temp)+1);
	//cout << temp << endl;
	delete [] temp; //очищаем буфер
	return st;
	} */

class Dictionary {
		char* name;
		Wordcard* arr;
		int size;
	public:
		Dictionary(char* n=(char*)"Eng-rus") {name=new char[strlen(n)+1]; name=strncpy(name,n,strlen(n)+1); arr=NULL; size=0;} //создаем словарь
		char* get_name() {return name; } 
		int get_size() {return size; }
		void chgname(char* n) {delete [] name; name=new char[strlen(n)+1]; name=strncpy(name,n,strlen(n)+1); } //меняем название словаря
		Wordcard* new1(int, int); //выделяем память для новой карточки
		void pushword(Wordcard); //добавляем карточку
		void delword(Wordcard); //удаляем карточку
		bool search(Wordcard); //поиск слова (и на русском, и на английском)
		void clear(); //очистка от копии
		char* operator [](char*);
		Dictionary operator=(const Dictionary &);
		friend ostream & operator <<(ostream &, const Dictionary &);
		~Dictionary() {delete[] name; if (!arr) delete[] arr;}
		friend Dictionary operator+(const Dictionary &, const Dictionary &);
		friend Dictionary operator-(const Dictionary &, const Dictionary &);
	};				

Wordcard* Dictionary:: new1(int r1, int r2) {
	Wordcard* tmp;
	tmp=new Wordcard[r2];
	for (int i=0; i<r1; i++) { // перекопирование в новый кусок памяти
		/*tmp[i].engword=new char[strlen(arr[i].engword)+1];
		tmp[i].engword=strncpy(tmp[i].engword, arr[i].engword, strlen(arr[i].engword)+1);
		tmp[i].translate=new char[strlen(arr[i].translate)+1];
		tmp[i].translate=strncpy(tmp[i].translate, arr[i].translate, strlen(arr[i].translate)+1); 
		tmp[i].rating=arr[i].rating;*/
		tmp[i]=arr[i];
		}
	size=r2;
	delete[] arr; //проверка на NULL
	arr=tmp;
	return arr;
	}

void Dictionary:: pushword(Wordcard w) {
	//cout << size << endl;
	arr=new1(size,size+1); //выделяем память
	/*arr[size-1].engword=new char[strlen(w.engword)+1];
	arr[size-1].engword=strncpy(arr[size-1].engword,w.engword,strlen(w.engword)+1);
	arr[size-1].translate=new char[strlen(w.translate)+1];
	arr[size-1].translate=strncpy(arr[size-1].translate,w.translate,strlen(w.translate)+1);
	arr[size-1].rating=w.rating;*/
	arr[size-1]=w;
	}

void Dictionary:: delword(Wordcard w) {
	cout << size << endl;
	for (int i=0; i<size; i++)
		if (arr[i]==w) { // поиск карточки
			for (int j=i; j<size-1; j++) {
				arr[j]=arr[j+1]; 
				//arr[j].engword=arr[j+1].engword;
				//arr[j].translate=arr[j+1].translate;
				//arr[j].rating=arr[j+1].rating;
				//char* на char*
				}
			size--;
		}
	}

bool Dictionary:: search(Wordcard w) {
	for (int i=0; i<size; i++) {
		if (strncmp(arr[i].engword,w.engword,strlen(w.engword)+1)==0) //если совпадают слова на английском
			return true;
		if (strncmp(arr[i].translate,w.translate,strlen(w.translate)+1)==0) //если совпадают слова на русском
			return true;
		}
	return false;
	}

void Dictionary:: clear() {
	for (int i=0; i<size; i++)
		for (int j=i; j<size; j++)
			if ((i!=j) && (arr[i]==arr[j])) { //если есть копия
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
		if (strncmp(arr[i].engword,word,strlen(word)+1)==0)
			return arr[i].translate;
		}
	return NULL;
	}

Dictionary Dictionary:: operator=(const Dictionary & d) {
	if (arr!=NULL)
		delete[] arr;
	size=d.size;
	arr=new Wordcard[size];
	for (int i=0; i<size; i++)
		arr[i]=d.arr[i];
	return *this;
	}	

ostream & operator <<(ostream & st, const Dictionary & d) {
	for (int i=0; i<d.size; i++) {
		st << d.arr[i].engword << "-" << d.arr[i].translate << "-" << d.arr[i].rating << endl;
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
			if (d1.arr[i]==d2.arr[j]) {
				flag=false;
				break;
				}
		if (flag)
			dans.pushword(d1.arr[i]);
		}
	return dans;	
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
	Wordcard w;
	Verb v;
	Noun n;
	while (readline(f,w,v,n)) {//(f >> w)
		if (w.engword!=NULL)
			d.pushword(w);
		if (v.engword!=NULL)
			d.pushword(v);
		if (n.engword!=NULL)
			d.pushword(n);
		//Освобождать память. 
		if (w.engword!=NULL) {
			delete[] w.engword;
			w.engword=NULL;
			}
		if (v.engword!=NULL) {
			delete[] v.engword;
			v.engword=NULL;
			}
		if (n.engword!=NULL) {
			delete[] n.engword;
			n.engword=NULL;
			}
		//cout << "noun " << n.engword << endl;
		}
	//cout << d;	
	//Wordcard u("prove","доказать",0);
	//d.delword(u);
	//cout << d << endl;
	//u.engword="book";
	//u.translate="книга";
	//d.delword(u);
	//for (int i=0; i<d.get_size(); i++)
		//if (d.arr[i]==u)
			//d.arr[i].chgrate(5);
	//cout << d;
	//bool flag=d.search(u);
	//cout << flag << endl;
	//cout << d.get_size() << endl;
	//cout << d["glasses"] << endl;
	/*Dictionary d1;
	ifstream f2;
	f2.open("dic2.txt");
	while (f2 >> w)
		d1.pushword(w);
	cout << d1 << endl;
	//cout << d << endl;
	cout << "Сумма\n" << d+d1 << endl; 
	//d1=d-d1;
	cout << "Разность\n" << d-d1 << endl;
	d1.clear();
	cout << d1 << endl;
	cout << d1.get_size() << endl; */
	//cout << d-d1;
	return 0;
	}
