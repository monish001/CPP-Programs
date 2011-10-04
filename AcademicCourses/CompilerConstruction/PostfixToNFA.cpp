//filename: RE_to_NFA_ver3.cpp 
//Next version is : PostfixToNFA.cpp
//Assumptions: 1. Input expression is infix and contains only a and b as input symbols. Example: b.a/(a/b)*.a.b.(a)*
//2. Concatenation OR Dot operator is explicitly entered.
//3. Expression is correct
//4. Precedence of * (Kleene-Closure) is higher and other operators ( / . ) have same precedence.

#include<stack>
#include<string>
using namespace std;
string convert(string, int&);
class RegEx{
public:
	RegEx(string reg, int st, int en):re(reg), start(st), end(en){}
	static int nextNodeNum;
	int start, end;
	string re;
};
int RegEx::nextNodeNum = 0;
int compareints (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
void printTable(int table[][4], const int startState, const int endState, const vector<int>& banStates){
	cout<<"Start state is "<<startState<<"\nEnd state is "<<endState<<"\n";
	cout<<" Node\t a\t b\t E\n------\t---\t---\t---\n";
	for(int node =0 ; node <= endState; node++){
		if(bsearch(&node, &banStates[0], banStates.size(), sizeof(int), compareints) != NULL)//if node exists in banStates
			continue;
		cout<<node<<"\t";
		(table[node][0] == -1)?(cout<<char(176)):(cout<<table[node][0]); cout<<"\t";
		(table[node][1] == -1)?(cout<<char(177)):(cout<<table[node][1]); cout<<"\t";
        (table[node][2] != -1)?(cout<<table[node][2]):(cout<<char(178));
        if(table[node][3] != -1)
			cout<<", "<<table[node][3];
        cout<<"\n";
	}
}
void PostfixToNFA(string re, int table[][4], vector<int>& banStates, int& endState){//input: postfix expression

	//table[i][j] : ith node with input as jth symbol. j =0 means a, =1 b, =2,3 epsilon
	memset(table, -1, 50*4*sizeof(int));
	
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
				banStates.push_back(b.start);
				RegEx a(stk.top()); stk.pop();
				table[a.end][0] = table[b.start][0];
				table[a.end][1] = table[b.start][1];
				table[a.end][2] = table[b.start][2];
				table[a.end][3] = table[b.start][3];
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
	int startState = stk.top().start; endState = stk.top().end;
	printTable(table, startState, endState, banStates);
}
