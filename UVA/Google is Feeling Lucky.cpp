#include<string>
#include<fstream>
#include<list>
#include<iostream>
using namespace std;
int main(){
	ifstream cin("Google is Feeling Lucky.txt");
	ofstream cout("Google is Feeling LuckyOut.txt");
	long long t;
	cin>>t;
	list<string> mymap;
	list<string>::iterator iter;
	for(long long i=1; i<=t; i++, mymap.clear()){
		int max = -1;
		for(int j=0; j<10; j++){
			string str; int r;
			cin>>str>>r;
			if(max <  r){
				max = r;
				mymap.clear();
				mymap.push_back(str);
			}else if( max == r)
				mymap.push_back(str);
		}
		cout<<"Case #"<<i<<":\n";
		for(iter=mymap.begin(); iter!=mymap.end(); iter++)
			cout<<*iter<<"\n";
	}
}
