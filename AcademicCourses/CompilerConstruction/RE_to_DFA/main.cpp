#include"InfixToPostfixForRE.cpp" 
#include"PostfixToNFA.cpp" 
#include"NfaToDfa.cpp" 
#include"DFA.cpp" 
/* There are bugs in NfaToDfa part.
 * Test cases
 * (a/b)*.a.b.b
 * BUG: 
        Input: a** 
        Input: (a*.b*)* 
        Output: Program Crashes
 */
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
//	findClosureForEachNFAState(table, extraStates, endState);

	map<set<int>, pair<set<int>, set<int> > > moves;
	map<set<int>, int> statesDFA;

	NfaToDfa(table, extraStates, startState, moves, statesDFA);
	
	cout<<"DFA states: Corresponding NFA states\n";
	printDFAStates(statesDFA);
	cout<<"\n";
	printDFATable( moves, statesDFA, endState, startState);

	fflush(stdin);
	getchar();
	return 0;
}
