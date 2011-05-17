//dynamicArray.cpp
#include<math.h>
#include<iostream>
using namespace std;

/*
Test case:
    array a;
	for(T i=1; i<=9; i++)
		a.push(i);
	for(T i=0; i<a.count(); i++)
		cout<<a[i]<<" ";
Output:
	1:1:1 pushed
	2:2:2 pushed
	Now 4 elements allowed.
	3:3:3 pushed
	4:4:4 pushed
	Now 8 elements allowed.
	5:5:5 pushed
	6:6:6 pushed
	7:7:7 pushed
	8:8:8 pushed
	Now 16 elements allowed.
	9:9:9 pushed
	1 2 3 4 5 6 7 8 9
Test case:
    array a(3);
	a[0]=12, a[1]=13, a[2] =14;
	for(T i=1; i<=2; i++)
		a.push(i);
	for(T i=0; i<a.count(); i++)
		cout<<a[i]<<" ";
Output:
	Now 6 elements allowed.
	1:4:1 pushed
	2:5:2 pushed
	12 13 14 1 2
Test case:
   array a(1);
	a[0]=12;
	for(T i=1; i<=2; i++)
		a.push(i);
	for(T i=0; i<a.count(); i++)
		cout<<a[i]<<" ";
Output:
	Now 2 elements allowed.
	1:2:1 pushed
	Now 4 elements allowed.
	2:3:2 pushed
	12 1 2
*/
typedef int T;
class array{
	T *ar;
	unsigned int sizeIndex;//index to the total number of items that can be stored into by-now-allocated memory
	int topIndex;//index to the item at the end/top
	public:
	array():ar(new T[2]),topIndex(-1), sizeIndex(1){}
	array(int N):topIndex(N-1),sizeIndex(N-1),ar(new T[N]){}
	unsigned count(){
		return topIndex+1;
	}
	bool push(T item){//to increase the arraysize;
		if(topIndex == sizeIndex){
			sizeIndex = (sizeIndex+1)*2-1;
			cout<<"Now "<<sizeIndex+1<<" elements allowed.\n";
			T *temp = new T[sizeIndex+1];
			for(int i=0; i<=topIndex; i++)				temp[i]=ar[i];//copy count-1 elements
			delete[] ar;
			ar=temp;
		}
		ar[++topIndex]=item;
		cout<<item<<":"<<topIndex+1<<":"<<ar[topIndex]<<" pushed\n";
	}
	//places (t)item at (int)index of variable array
	bool push(int index, T item){//to increase the arraysize;
		if(index<=topIndex){
			*(ar+index)=item;
			return true;
		}
		for(;topIndex<index;)
			this->push(-1);
		this->push(item);
		return true;
	}
	T& operator[](int index){//for reading or writing into the array
		if(index<0){
			cout<<"ERROR: Array Underflow\nProgram is terminating. Press any key.\n";
			fflush(stdin);
			getchar();
			exit(0);
		}
		if(index>topIndex){
			cout<<"ERROR: Array Overflow\nProgram is terminating. Press any key.\n";
			fflush(stdin);
			getchar();
			exit(0);
		}
		return ar[index];	
	}
};

int main(){
    array a(1);
	a[0]=12;
	for(T i=1; i<=2; i++)
		a.push(i);
	a.push(9, 200);
	a.push(0, 200);
	a[9]=100;
	for(T i=0; i<a.count(); i++)
		cout<<a[i]<<" ";
	fflush(stdin);
	getchar();
	return 0;
}