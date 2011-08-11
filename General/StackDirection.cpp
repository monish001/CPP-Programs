#include<iostream>
#include<stack>
using namespace std;

//#error some wrong condition

int main(){
	stack<int> s;
	s.push(10);
	s.push(120);
	cout<<"Add of 120: "<<&(s.top())<<"\nAdd of 10";
	s.pop();
	cout<<&(s.top());
	getchar();
	return 0;
}
