//NOT TESTED
//File: SmartPointer.cpp
/**
*
*/
#include<iostream>

using namespace std;
template <typename T> class SmartPointer{
public:
	SmartPointer(T* ptr){//Constructor
		ref=ptr;
		ref_count = new int;
		*ref_count=1;
	}
	SmartPointer(SmartPointer<T>& t){//Copy Constructor
		ref = t.ref;
		ref_count = t.ref_count;
		++*ref_count;
	}
	SmartPointer<T>& operator=(SmartPointer<T>& t){
		if((this != &t) && (this->ref != t.ref)){
			--*ref_count;
			if(*ref_count == 0){
				delete ref_count;
				delete ref;
				ref_count=NULL;
				ref=NULL;
			}
		ref = t.ref;
		ref_count = t.ref_count;
		++*ref_count;
		}
		return *this;
	}
	T getValue(){
		return *ref;
	}
	~SmartPointer(){
		--*ref_count;
		if(*ref_count == 0){
			delete ref_count;
			delete ref;
			ref_count=NULL;
			ref=NULL;
		}
	}
protected:
	T* ref;
	int* ref_count;
};
int main(){
	SmartPointer<int> s(new int);
	s=s;
	SmartPointer<int> t(s);
	//s=t;
	getchar();
	return 0;
}
