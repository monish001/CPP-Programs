//Functions can NOT access base class functions 
#include<iostream>
using namespace std;
class Base{
private:
    int x;
    virtual void f1() const{
        cout<<"Base: In f1()";
    }
public:
    Base():x(10){}
    void printx(){cout<<"Base: "<<this->x<<"\n";};
};
class Derv: public Base{
      public:
    virtual void f1(){
        cout<<"Derv: In f1()";
//        Base::f1();
    }
};
int main(){
    Derv a;
    a.Base::f1();
    getchar();
    return 0;
}
