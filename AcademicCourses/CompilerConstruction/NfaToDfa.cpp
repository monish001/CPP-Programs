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
void findClosureForEachState(int table[][4], vector<int>& banStates, const int& endState){
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
set<int> _findNextDFAState(map< set<int>, bool>& statesDFA){
	 //it;
	for(map< set<int>, bool>::iterator it=statesDFA.begin(); it!=statesDFA.end(); it++)
	if(it->second == false)
		return it->first;
	set<int> tmp;
	return tmp;
}
void NfaToDfa(const int table[][4], const vector<int>& banStates, const int& endState, const int& startState){
	map<set<int>, bool> statesDFA;
	set<int> aSet = _closure(startState, table);
	statesDFA[aSet] = 0;
	do{
		set<int> intSet = _moveAndReturnClosure(aSet, 0, table);//Input symbol is a
		if( (statesDFA.find(intSet))==statesDFA.end() )//tmp not already present in statesDFA
			statesDFA[intSet]=0;
		
		intSet = _moveAndReturnClosure(aSet, 1, table);//Input symbol is a
		if( (statesDFA.find(intSet))==statesDFA.end() )//tmp not already present in statesDFA
			statesDFA[intSet]=0;

		statesDFA[aSet] = 1;//done
		aSet = _findNextDFAState(statesDFA);
	}while(aSet.size() != 0);
	
}
