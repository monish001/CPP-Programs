//filename: RE_to_NFA.cpp
//Assumptions: 1. Input expression is postfix. 
//2. Dot operator is explicitly entered.
//3. Expression is correct
#include<iostream>
#include<map>
#include<stack>
using namespace std;
class RegEx{
public:
	RegEx(string reg, int st, int en):re(reg), start(st), end(en){}
	static int nextNodeNum;
	int start, end;
	string re;
};
int RegEx::nextNodeNum = 0;
void solve(string re){//input: postfix expression
	char table[50][3] = {'\0'};//table[i][j] : ith node with input as jth symbol
	map<int, int> copy;//to store the info of overlapping states/node
	stack<RegEx> stk;
	for(int i=0; re[i]; i++){
		switch(re[i]){
int state1, state2;
			case '*':
				RegEx & a = stk.top(); stk.pop();
				table[a.end][2] = a.start;
				state1 = (RegEx::nextNodeNum)++;
				table[state1][2] = a.start;
				a.start = state1;
				
				state2 = (RegEx::nextNodeNum)++;
				table[a.end][2] = state2;
				table[state1][2] = state2;
				a.end = state2;
				a.re += "*";
				break;
/*			case '.':
				break;
			case '/':
				break;*/
			default://make RegEx object and push it into stk
				state1 = (RegEx::nextNodeNum)++;
				state2 = (RegEx::nextNodeNum)++;
				//RegEx a(re[i], (RegEx.nextNodeNum)++, (RegEx.nextNodeNum)++);
				RegEx b(re[i]+"", state1, state2);
				stk.push(b);
		}
		cout<<"Node\ta\tb\tE\n";
		for(int node =0 ; node<50; node++){
			cout<<node<<"\t"<<table[0]<<"\t"<<table[1]<<"\t"<<table[2]<<"\n";
		}
	}
}
int main(){
	string re_postfix;
	cin>>re_postfix;
	solve(re_postfix);
	return 0, getchar();
}
