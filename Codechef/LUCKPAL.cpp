//WRONG ANSWER
//filename: LUCKPAL.cpp
/* PROBLEM STATEMENT
Chef Palin, as his name suggests, is always very interested in palindromic strings. Recently, he made a pretty interesting discovery on palindromes and that made him feel really Lucky. He came across something known as Lucky Palindromes. He defines a string as being a lucky palindrome if it is a palindrome containing the string "lucky" as a substring. As always, now he wants to turn every string he comes across into a lucky palindrome. Being a chef, he is a man of patience and creativity, so he knows the operation of replacing any character of the string with any other character very well and he can perform this action infinitely many times. He wants you to write a program that can help him convert a given string to a lucky palindrome using the minimum number of operations and if several such lucky palindromes are possible, then output the lexicographically smallest one.

Input

The first line contains a single integer T <= 100 the number of testcases. The following T lines each contain a string of length <= 1000 and only containing characters 'a'-'z'.

Output

For each line of testcase, your program should output on a single line, the required lucky palindrome along with the minimum number of operations, both separated by a single space. If there is no lucky palindrome possible, then just output "unlucky" in a single line.

Example:

Input

3
laubcdkey
luckycodechef
aaaaaaaa

Output

luckykcul 8
luckycocykcul 6
unlucky
*/
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#define INF (32000)
using namespace std;
char lucky[6]="lucky";
int getCost(const string& orig, const string& changed){
	int cost=0;
	for(int i=0; i<orig.size(); i++){
		if(orig[i]!=changed[i])
			cost++;
	}
	return cost;
}
int replaceWithLucky(const int pos, string& resStr, const string& str){
	int len = resStr.size();
	for(int i=pos; i<pos+5; i++)
		resStr[i]=resStr[len-1-i]=lucky[i-pos];
	for(int i=0; i<len/2; i++){
		(resStr[i] < resStr[len-1-i])?(resStr[len-1-i] = resStr[i]):(resStr[i] = resStr[len-1-i]);
	}
	if(strstr(&(resStr[0]),"lucky")==NULL)
		return INF;
	return getCost(str, resStr);
}
void isLucky(const string& origStr){
	int len=origStr.size();
	if(len < 9){
		cout<<"unlucky\n";
		return;
	}
	int halfLen = len/2;
	int minCost = INF;
	string bestStr;
	for(int i=0; i+4<len; i++){
	string curStr(origStr);
		int curCost = replaceWithLucky(i, curStr, origStr);
		if( (curCost<minCost) || (curCost == minCost && !strcmp(&bestStr[0], &curStr[0])) ){
			minCost = curCost;
			bestStr = curStr;
		}
	}
	cout<<bestStr<<" "<<minCost<<"\n";
}
int main(){
	int t;
	ifstream cin("LUCKPAL_in.txt");
	for(cin>>t ; t>0; t--){
		string s;
		cin>>s;
		isLucky(s);
	}
	getchar();
	return 0;
}
