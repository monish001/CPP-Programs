#include<iostream>
#include<conio.h>
using namespace std;

class Base {
public: int a;
};

class Der: private Base{
public:
	void print(){
		cout<<a;
	}
};
int main(){
	Der c;
	c.print();
	return 0;
}
