#include<set>
#include<map>
set<int> closure(int state, int table[][4]){
	set<int> aSet;
	aSet.insert(state);
	if(table[state][2] != -1){
		set<int> tmpSet = closure(table[state][2], table);
		aSet.insert(tmpSet.begin(), tmpSet.end());
	}
	if(table[state][3] != -1){
		set<int> tmpSet = closure(table[state][3], table);
		aSet.insert(tmpSet.begin(), tmpSet.end());
	}
	return aSet;
}
void findClosureForEachState(int table[][4], vector<int>& banStates, const int& endState){
	for(int node =0 ; node <= endState; node++){
		if(bsearch(&node, &banStates[0], banStates.size(), sizeof(int), compareints) != NULL)//if node exists in banStates
			continue;

		set<int> myset	= closure(node, table);
		//print
		set<int>::iterator it;
		for (it=myset.begin(); it!=myset.end(); it++)
			cout << " " << *it;
		cout << endl;
	}
}
void NfaToDfa(int table[][4], vector<int>& banStates, const int& endState){
	
}