#include<set>
#include<map>
set<int> _closure(int state, const int table[][4]){
	set<int> aSet;
	aSet.insert(state);
	if(table[state][2] != -1){
		set<int> tmpSet = _closure(table[state][2], table);
		aSet.insert(tmpSet.begin(), tmpSet.end());
	}
	if(table[state][3] != -1){
		set<int> tmpSet = _closure(table[state][3], table);
		aSet.insert(tmpSet.begin(), tmpSet.end());
	}
	return aSet;
}
set<int> _closure(const set<int>& myset, const int table[][4]){
	set<int> aSet;
	set<int>::iterator it;
	for (it=myset.begin(); it!=myset.end(); it++){
		set<int> tmp = _closure(*it, table);
		aSet.insert(tmp.begin(), tmp.end());
	}
	return aSet;
}
void findClosureForEachNFAState(int table[][4], vector<int>& banStates, const int& endState){
	for(int node =0 ; node <= endState; node++){
		if(bsearch(&node, &banStates[0], banStates.size(), sizeof(int), compareints) != NULL)//if node exists in banStates
			continue;

		set<int> myset	= _closure(node, table);
		//print
		set<int>::iterator it;
		for (it=myset.begin(); it!=myset.end(); it++)
			cout << " " << *it;
		cout << endl;
	}
}

set<int> _moveAndReturnClosure(set<int> aSet, const int input, const int table[][4]){
	set<int> intSet;
	set<int>::iterator it;
	for (it=aSet.begin(); it!=aSet.end(); it++)
	if(table[*it][input] != -1){//there is some move
		set<int> tmpSet = _closure(table[*it][input], table);
		intSet.insert(tmpSet.begin(), tmpSet.end());
	}
	return intSet;
}
/*
 * returns next unexplored DFA state
 */
set<int> _findNextDFAState(map< set<int>, int>& statesDFA){
	for(map< set<int>, int>::iterator it=statesDFA.begin(); it!=statesDFA.end(); it++)
	if(it->second == false)
		return it->first;
	set<int> tmp;
	return tmp;
}
void _printDFA( map< set<int>,pair<set<int>,set<int> > >& moves, map<set<int>, int>& statesDFA){
	cout<<"\nDFA:\nState\tInput a\tInput b\n";
	for(map<set<int>, int>::iterator it=statesDFA.begin(); it!=statesDFA.end(); it++){
		cout<<(*it).second<<"\t";
        cout<<statesDFA[(moves[(*it).first]).first]<<"\t";
        cout<<statesDFA[(moves[it->first]).second]<<"\n";
	}
}
vector<int> _getCorrDFAStates(map<set<int>, int>& statesDFA, const int& startState){
	vector<int> aVector;
	for(map<set<int>, int>::iterator it=statesDFA.begin(); it!=statesDFA.end(); it++){
		if((it->first).find(startState) != (it->first).end())//startState present in it->first
			aVector.push_back(statesDFA[it->first]);
	}
	return aVector;
}
void _printStartState(map<set<int>, int>& statesDFA, const int& startState){
	vector<int> start = _getCorrDFAStates(statesDFA, startState);
	if(start.size()==1){
		cout<<"Start state is "<<start[0]<<"\n";
		return;
	}
	cout<<"Start states are ";
	for(int i=0; i<start.size(); i++)
		cout<<start[i]<<" ";
}
void _printEndState(map<set<int>, int>& statesDFA, const int& endState){
	vector<int> end = _getCorrDFAStates(statesDFA, endState);
	if(end.size()==1){
		cout<<"End state is "<<end[0]<<"\n";
		return;	
	}
	cout<<"End states are ";
	for(int i=0; i<end.size(); i++)
		cout<<end[i]<<" ";
}
void NfaToDfa(const int table[][4], const vector<int>& banStates, const int& endState, const int& startState){
	map<set<int>, pair<set<int>, set<int> > > moves;
	map<set<int>, int> statesDFA;
	set<int> aSet = _closure(startState, table);
	statesDFA[aSet] = 0;
	do{
		set<int> intSet = _moveAndReturnClosure(aSet, 0, table);//Input symbol is a
		if( intSet.size()!=0 && statesDFA.find(intSet)==statesDFA.end() )//set not already present in statesDFA
			statesDFA[intSet]=0;
		
		set<int> intSet2 = _moveAndReturnClosure(aSet, 1, table);//Input symbol is a
		if( (intSet2.size()!=0) && statesDFA.find(intSet2)==statesDFA.end() )//set not already present in statesDFA
			statesDFA[intSet2]=0;

		moves[aSet] = make_pair(intSet, intSet2);
		
		statesDFA[aSet] = 1;//done
		aSet = _findNextDFAState(statesDFA);
	}while(aSet.size() != 0);
	
	
	{
		int i=1;//number the new states
		for(map<set<int>, int>::iterator it=statesDFA.begin(); it!=statesDFA.end(); it++)
			if((it->first).size() != 0)
				it->second = i++;
			else it->second = -1;
	}
	
	_printStartState(statesDFA, startState);
	_printEndState(statesDFA, endState);
	_printDFA( moves, statesDFA);
	
}
//int main(){}
