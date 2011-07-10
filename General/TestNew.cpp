//File: TestNew.cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
class base{
public:
	int x;
	base():x(10){
		cout<<"In base()\n";
	}
	base(int y):x(y){
		cout<<"In base(int)\n";
	}
	void* operator new(size_t size) throw(bad_alloc){
		cout<<"In Operator new\n";
		void *p = malloc(size);
		if(!p)
			throw bad_alloc();
		cout<<"Ending Operator new\n";
		return p;
	}
	void* operator new[](size_t size) throw(bad_alloc){
		cout<<"In Operator new[] : "<<size<<"\n";
		void *p = malloc(size);
		if(!p)
			throw bad_alloc();
		cout<<"Ending Operator new[]\n";
		return p;
	}
};
int main(){
    base *b = new base();
    base *bf = new base(15);
	cout<< b->x << " " << bf->x<<"\n";
	delete b;
	delete bf;

	b = new base[1];
	cout<< b[0].x <<"\n";
//	bf = new base[2];
//	cout<< bf[0].x<<"\n";
	getchar();
}
