/*
* Author : Monish Gupta
* Language: C++
* If alternate solutions are present, all are printed.
**/
/*
Longest Palindromic Sequence

A palindromic sequence is the sequence which is equal to itself when reversed. For ex. the human Y-Chromosome contains a gene with the amino acid sequence <C,A,C,A,A,T,T,C,C,C,A,T,G,G,G,T,T,G,T,G,G,A,G>, which includes the palindromic sub sequences <T,G,G,G,T> and <T,G,T>.

Devise an efficient algorithm that takes a DNA sequence and returns the length of longest palindromic subsequence.

Sample Input

<C,A,C,A,A,T,T,C,C,C,A,T,G,G,G,T,T,G,T,G,G,A,G>


Sample Output

5
<T,G,G,G,T>
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void print(string & s){
	cout<<"<"<<s[0];
	for(int i=1; i<s.length(); i++){
		cout<<","<<s[i];
	}
	cout<<">\n";
}
int isPalindrome(string & s){
	string tmp(s.rbegin(), s.rend());
	return !(s.compare(tmp));
}
int main(){
	string str="",s2;
	cin>>s2;
	for(int i=0; i<s2.length(); i++){
		if(i%2 == 0)
			continue;
		str += s2[i];
	}
	int flag=1;
	for(int len = str.length(); flag; len--){
		for(int i=0; ; i++){
			string temp(str.substr(i, len));
			assert(temp.length() <= len);
			if(temp.length() < len)
				break;
			if(isPalindrome(temp)){//cout<<temp;
				flag=0; 
				print(temp);
				//break;
			}
		}// cout<<len<<"\n";
	}
	fflush(stdin);
	getchar();
	return 0;
}
