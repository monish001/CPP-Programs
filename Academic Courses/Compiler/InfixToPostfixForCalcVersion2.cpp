//filename: InfixToPostfix.cpp
//Assumptions: 
//1. Input expression is infix. Example: ((a+b)-(c/d))*e+f*g
//2. All operators (* / + -) have same precedence. Associativity is left to right.
//3. Expression is correct
//4. Circular brackets: '(' and ')' are allowed in expressions

#include<iostream>
#include<queue>
using namespace std;
string convert(string in, int& i){
	queue<string> q;
	string out("");
	for(; in[i] != ')'; i++){
		//putchar(in[i]);
		switch(in[i]){
			case '+':
			case '/':
			case '*':
			case '-':
			{
				char oper = in[i++];
				q.push((in[i] == '(')?(convert(in, ++i)):(string(1,in[i])));
				q.push(string(1,oper));
				break;
			}
			case '(':
				q.push(convert(in, ++i));
				break;
			default:
			{	
				q.push(string(1,in[i]));
			}
		}
	}
	while(!q.empty()){
//		cout<<q.front();
		out+=q.front();
		q.pop();
	}
	return out;
}

int main(){
	string re_postfix, in;
//	cout<<(string(1,'a')+"")<<"\n";
	cin>>in;
    int index = 0;
	cout<<convert(in+')', index);
    
	fflush(stdin);
	getchar();
	return 0;
}
