//filename: InfixToPostfix.cpp
//Assumptions: 
//1. Input expression should not contain brackets.
//2. Input expression is infix. Example: ((2+3).(25/3))*8+34*3
//3. Concatenation OR Dot operator is explicitly entered.
//4. Expression is correct

#include<iostream>
#include<stack>
using namespace std;

int main(){
	string re_postfix, in;
	cin>>in;
	string stk("");

	for(int i=0; i<in.size(); i++){
		//putchar(in[i]);
		switch(in[i]){
			case '+':
			case '/':
			case '*':
			case '-':
			{
				char tmp = in[i++];
				stk += in[i];
				stk += tmp;
				break;
			}
			default:
			{	
				stk+= in[i];
			}
		}
	}
	cout<<stk;

	fflush(stdin);
	getchar();
	return 0;
}
