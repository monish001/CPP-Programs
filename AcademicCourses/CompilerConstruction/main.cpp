#include"InfixToPostfixForRE.cpp" 
#include"PostfixToNFA.cpp" 
#include"NfaToDfa.cpp" 
int main(){
	string in;
	cin>>in;
	int i=0;

	string regex_postfix = convert(in + ')', i);
	cout<<"Postfix: "<<regex_postfix<<"\n";
	int table[50][4];
	vector<int> extraStates;
	int endState, startState;
	PostfixToNFA(regex_postfix+"#" , table, extraStates, startState, endState);
//	findClosureForEachState(table, extraStates, endState);
	NfaToDfa(table, extraStates, endState, startState);
	fflush(stdin);
	getchar();
	return 0;
}
