//DFA.CPP
/*
 * Returns the DFA state numbers which have NFA state 'NFAState'
 */
vector<int> _getCorrDFAStates(map<set<int>, int>& statesDFA, const int& NFAState){
	vector<int> aVector;
	for(map<set<int>, int>::iterator it=statesDFA.begin(); it!=statesDFA.end(); it++){
		if((it->first).find(NFAState) != (it->first).end())//NFAState present in it->first
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
	cout<<"\n";
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
	cout<<"\n";
}
/*Prints the DFA state table*/
void printDFATable( map< set<int>,pair<set<int>,set<int> > >& moves, map<set<int>, int>& statesDFA, const int& endState, const int& startState){
    _printStartState(statesDFA, startState);
	_printEndState(statesDFA, endState);
	cout<<"State\ta\tb\n";
	for(map<set<int>, int>::iterator it=statesDFA.begin(); it!=statesDFA.end(); it++){
		cout<<(*it).second<<"\t";
		int tmp = statesDFA[(moves[(*it).first]).first];
        cout<<char((tmp!=0)?(tmp+'0'):(177))<<"\t";
		tmp = statesDFA[(moves[(*it).first]).second];
        cout<<char((tmp!=0)?(tmp+'0'):(177))<<"\n";
	}
}



/*Prints set<int> elements as a space seperated list*/
void _printSetIntElems(const set<int>& intSet){
	for(set<int>::iterator it=intSet.begin(); it!=intSet.end(); it++)
		cout<<*it<<" ";
}
/*
 * Output Format:
 * DFAState followed by the NFA states it contains
 */
void printDFAStates(map< set<int>,int >& statesDFA){
	for(map<set<int>, int>::iterator it = statesDFA.begin(); it!=statesDFA.end(); it++){
		cout<<it->second<<": ";
		_printSetIntElems(it->first);
		cout<<"\n";
	}
}
