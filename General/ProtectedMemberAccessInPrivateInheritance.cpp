//Yes, They can be accessed. Protected members become private in derived class in private inheritance. Now the derived class can access these inherited private members.
#include<iostream>
using namespace std;
class Base{
protected:
    int x;
public:
    Base():x(10){cout<<"in Base\n";}
    void printx(){cout<<"Base: "<<this->x<<"\n";}
};
class Derv: private Base{
public:
	Derv(){
		cout<<"in drv "<<x<<"\n";
		printx();
	}
};
int main(){
    Derv a;
    getchar();
    return 0;
}
