/*
 * Author: Monish Gupta
 * monish.gupta1@gmail.com
 * Thapar University, Patiala. PIN:147004
 * ASSUMPTION: EACH EDGE IS GIVEN ONCE. EITHER V1 TO V2 OR V2 TO V1.
 */
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<set>
#include<map>
#include<vector>
#include<utility>
#include<stack>
#include <algorithm>

using namespace std;
ofstream out("output.txt");

/*
this class is used in perform function
*/
class state{
	public:
	int curnode;//current node
	unsigned long long curprod;//current product
	set<int> visited;//stores all the node visited to reach 'curnode' from termination vertex.
	state(int n, unsigned long long p, set<int> s){
		curnode = n;
		curprod = p;
		visited = s;
	}
	state(int n, unsigned long long p, set<int> s, int v2){
		curnode = n;
		curprod = p;
		visited = s;
		visited.insert(v2);
	}
};

/*
Input:
	node : last vertex number where message terminated
	prod : product received at 'node'
	st : an empty set which will be populated with all the possible originating vertices
	mp : information of all the egdes in the graph
*/
void  perform(const int node, const unsigned long long prod, set<int>& st, map<int, vector< pair<int, int> >* >& mp){
	stack< state > stk;
	set<int> visited;
	visited.insert(node);
	stk.push(state(node, prod, visited));
	cout<<node<<" pushed."<<endl;
	while(!stk.empty()){
		state stt = stk.top(); 		stk.pop();
		if(stt.curprod == 1){
			st.insert(stt.curnode);
			continue;
		}
		if(mp.find(stt.curnode)!=mp.end())
		for(int i=0; i< (mp[stt.curnode])->size(); i++){
			int v2 = (*(mp[stt.curnode]))[i].first;
            int wt = (*(mp[stt.curnode]))[i].second;
			if(stt.curprod%wt == 0 && (stt.visited).find(v2)==(stt.visited).end()){
				cout<<v2<<" pushed from "<<stt.curnode<<endl;
				stk.push(state(v2, (stt.curprod)/wt, stt.visited, v2));
			}
		}
		cout<<stt.curnode<<" poped."<<endl;
	}
}

/*
Prints NULL followed by new line if given set is empty.
Else prints elements of set as a space seperated list followed by new line.
*/
void printSet(const set<int>& myset){
	set<int>::iterator it;

	if(myset.size() == 0)
		out<<"NULL";
	else for ( it=myset.begin() ; it != myset.end(); it++ )
			out << *it<<" ";
	out<<endl;
}
/*
Free dynamically allocated vector< pair<int, int> > in given map
*/
void freeMap(map<int, vector< pair<int, int> >* >& mp){
	map<int, vector< pair<int, int> >* >::iterator it;
	for(it=mp.begin(); it!=mp.end(); it++)
		delete (*it).second;
}

int main(){
//initialize input output files
	filebuf fb;
	fb.open ("input.txt",ios::in);
	istream cin(&fb);

//read number of vertices and number of edges
	int nv, ne;
	string tmp;
	cin>>tmp>>nv>>ne;
	cout<<tmp<<endl<<nv<<" "<<ne<<endl;

//read information about edges
	int v1, v2, w;
	map<int, vector< pair<int, int> >* > mp;
	cin>>tmp>>tmp; cout<<tmp<<endl;
	for(int i=0; i<ne; i++){
		cin>>v1>>v2>>w;
		cout<<v1<<" "<<v2<<" "<<w<<endl;
		if(mp.find(v1) == mp.end())
			mp[v1] = new vector< pair<int, int> >;
		mp[v1]->push_back(make_pair(v2, w));
		if(mp.find(v2) == mp.end())
			mp[v2] = new vector< pair<int, int> >;
		mp[v2]->push_back(make_pair(v1, w));
	}

//Read each terminating vertex number and corresponding product and find originating vertices
	cin>>tmp;
	set<int> ans;
	int node; unsigned long long val;

	cin>>node>>val;
    cout<<node<<" "<<val<<endl;
    perform(node, val, ans, mp);
    printSet(ans);
	while( !cin.eof() ) {
		set<int> tmp, tmp2 = ans;
		ans.clear();
		cin>>node>>val;
		cout<<node<<" "<<val<<endl;
		perform(node, val, tmp, mp);
		printSet(tmp);//print all possible originating vertices corresponding to the current message
	    set_intersection(tmp2.begin(), tmp2.end(), tmp.begin(), tmp.end(), std::inserter( ans, ans.begin() ));
	}
	printSet(ans);//print intersection of sets of originating vertices.
	freeMap(mp);//clean dynamic memory of vectors
	fb.close();
	out.close();
	getchar();
	return 0;
}
