/*
* Author : Monish Gupta
* Assuimg only unique solution is possible if any
**/
/*
Word Breaking

Given a dictionary that can tell you whether a string is valid word or not in the constant time and given a string s of length n, provide an efficient algorithm that can tell whether s can be reconstituted as a sequence of valid words. In the event that your string is valid, your algorithm should output the corresponding sequence of words.

First line of input contains number of dictionary words i.e. D. Followed by D lines each containing the dictionary word.
Next line contains word to be tested.
Output should contain the dictionary words combining which we get the word to be tested in the same order as they appear in that word.

Sample Input

5
bed
test
bath
and
beyond
bedbathbeyond


Sample Output


bed
bath
beyond

*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int breakF() throw(){
	cout<<"No";
    exit(0);
}
int main(){
	vector<string> wd;
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		string str;
		cin>>str;
		wd.push_back(str);
	}
	string str; cin>>str;
	int flag=0;
	for(int i=0; str != ""; (1+i == n)?((flag)?(i=0):(breakF())):(i++) ){
		if(wd[i] == str.substr(0, wd[i].length())){
			str = str.substr(wd[i].length());
			cout<<wd[i]<<"\n";
			flag = 1;
		}
	}
	return 0;
}
