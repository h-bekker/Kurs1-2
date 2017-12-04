#include <iostream>
#include <cstring>
using namespace std;

class Ball {
		char* color;
		int diam;
	public:
		friend int smallest(Ball,Ball,Ball);
		Ball(int k, const char* str="white"){diam=k; color=new char[strlen(str)+1]; color=strncpy(color,str,strlen(str)); color[strlen(str)]='\0'; };
		//Ball(const char* str="white", int k=1){diam=k; color=new char[strlen(str)+1]; color=strncpy(color,str,strlen(str)); color[strlen(str)]='\0'; };
		~Ball() {cout << color << endl; delete [] color; };
	};

int smallest(Ball a, Ball b, Ball c) {
	int k;
	if (a.diam<b.diam)
		k=a.diam;
	else
		k=b.diam;
	if (k>c.diam)
		k=c.diam;
	return k;
	}

int main() {
	Ball gb(20,"green"),//мяч цвета "green", диаметр - 20
	wb(12),//мяч цвета "white", диаметр - 12
	b(10);//мяч цвета "white", диаметр - 10
	cout<<"The smallest:"<<smallest(gb,wb,b)<<" end "<<endl;
	//должен быть напечатан диаметр самого маленького из мячей
	return 0;
	}
