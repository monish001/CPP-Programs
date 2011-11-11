#include<iostream>
using namespace std;
class A{
public:
	A(){}
	virtual ~A(){
		f1();
		cout<<"A: in dtor\n";
	}
	virtual void f1(){
		cout<<"A: in f1()\n";
	}
	virtual void f2(){
		cout<<"A: in f2()\n";
	}
};
class B: public A{
public:
	B(){}
	~B(){
		f1();
		cout<<"B: in dtor\n";
	}
	virtual void f1(){
		cout<<"B: in f1()\n";
	}
	virtual void f2(){
		cout<<"B: in f2()\n";
	}
};
int main(){
   A *a = new A();
   A *b = new B();
   
   a->f1();
   a->f2();
   b->f1();
   b->f2();
   
   delete a;
   delete b;
   return 0;
}
/*
output:
A: in f1()
A: in f2()
B: in f1()
B: in f2()
//dtor a called
A: in f1()
A: in dtor

//dtor b called
B: in f1();
B: in dtor
A: in f1();
A: in dtor

*/
