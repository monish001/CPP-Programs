//filename: RE_to_NFA_ver1.cpp
//Assumptions: 1. Input expression is postfix. Example: ab.ab/.*
//2. Concatenation OR Dot operator is explicitly entered.
//3. Expression is correct

#include<iostream>
//#include<map>
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
     
	int table[50][4];//table[i][j] : ith node with input as jth symbol. j =0 means a, =1 b, =2,3 epsilon
	memset(table, -1, 50*4*sizeof(int));
	//map<int, int> copy;//to store the info of overlapping states/node
	stack<RegEx> stk;
	for(int i=0; re.at(i) != '#'; i++){
		switch(re.at(i)){
			case '*':{
				RegEx a(stk.top());
				stk.pop();
				table[a.end][2] = a.start;
				int state1 = (RegEx::nextNodeNum)++;
				table[state1][2] = a.start;
				a.start = state1;
				
				int state2 = (RegEx::nextNodeNum)++;
				table[a.end][3] = state2;
				table[state1][3] = state2;
				a.end = state2;
				a.re += "*";
				stk.push(a);
				break;	}
			case '.':{
				RegEx b(stk.top()); stk.pop();
				RegEx a(stk.top()); stk.pop();
				table[a.end][2] = b.start;
				stk.push(RegEx(a.re+b.re+".", a.start, b.end));
				break;}
			case '/':{
				RegEx b(stk.top()); stk.pop();
				RegEx a(stk.top()); stk.pop();
                int state1 = (RegEx::nextNodeNum)++;
				int state2 = (RegEx::nextNodeNum)++;
				table[state1][2] = a.start;
				table[state1][3] = b.start;
				table[a.end][2] = state2;
				table[b.end][2] = state2;
				stk.push(RegEx(a.re +b.re+"/", state1, state2));
				break;}
			default://make RegEx object and push it into stk
				{
                 int state1 = (RegEx::nextNodeNum)++;
				int state2 = (RegEx::nextNodeNum)++;
				//RegEx a(re[i], (RegEx.nextNodeNum)++, (RegEx.nextNodeNum)++);
				table[state1][re.at(i) - 'a'] = state2;
				RegEx b(re[i]+"", state1, state2);
				stk.push(b);	}
		}
	}
	cout<<"Start state is "<<stk.top().start<<"\nEnd state is "<<stk.top().end<<"\n";
	cout<<"Node\ta\tb\tE\n";
	for(int node =0 ; node < RegEx::nextNodeNum; node++){
		cout<<node<<"\t";
		(table[node][0] == -1)?(cout<<'\0'):(cout<<table[node][0]); cout<<"\t";
		(table[node][1] == -1)?(cout<<'\0'):(cout<<table[node][1]); cout<<"\t";
        if(table[node][2] != -1)
            cout<<table[node][2];
        if(table[node][3] != -1)
			cout<<", "<<table[node][3];
        cout<<"\n";
	}
}
int main(){
	string re_postfix;
	cin>>re_postfix;
	solve(re_postfix+"#" );
	
	fflush(stdin);
	getchar();
	return 0;
}
