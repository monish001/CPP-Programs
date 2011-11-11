//filetype: BonnieAndClyde.cpp
//Status: Time Limit Exceeded on test 28
/* Question: http://acm.sgu.ru/problem.php?contest=38&problem=B
B. Bonnie and Clyde
Time limit per test: 3 second(s)
Memory limit: 262144 kilobytes
input: standard
output: standard

Bonnie and Clyde are into robbing banks. This time their target is a town called Castle Rock. There are n banks located along Castle Rock's main street; each bank is described by two positive integers xi, wi, where xi represents the distance between the i-th bank and the beginning of the street and wi represents how much money the i-th bank has. The street can be represented as a straight line segment, that's why values of xi can be regarded as the banks' coordinates on some imaginary coordinate axis.

This time Bonnie and Clyde decided to split, they decided to rob two different banks at a time. As robberies aren't exactly rare in Castle Rock, Bonnie and Clyde hope that the police won't see the connection between the two robberies. To decrease the chance of their plan being discovered by the investigation, they decided that the distance between the two robbed banks should be no less than d.

Help Bonnie and Clyde find two such banks, the distance between which is no less than d and the sum of money in which is maximum.

Input
The first input line contains a pair of integers n, d (1 = n = 2 · 105, 1 = d = 108), where n is the number of banks and d is the minimum acceptable distance between the robberies. Then n lines contain descriptions of banks, one per line. Each line contains two integers xi, wi (1 = xi,wi = 108), xi shows how far the i-th bank is from the beginning of the street and wi shows the number of money in the bank. Positions of no two banks coincide. The banks are given in the increasing order of xi.

Output
Print two integer numbers — indicies of the required banks. The banks are numbered starting from 1 in the order in which they follow in the input data. You may print indicies in any order. If there are many solutions, print any of them. If no such pair of banks exists, print "

-1 -1

" (without quotes).

Example(s)

sample input

	

sample output

6 3
1 1
3 5
4 8
6 4
10 3
11 2

	

5 3




Online Contester Team © 2002 - 2010. All rights reserved.
*/
#include<iostream>
#include<vector>
#include<climits>
#include<cstdarg>
#include<algorithm>
#include<fstream>
using namespace std;

int main(){
	ff
	getchar();
}

/*//bool compare(const bank& a, const bank& b){	return a.dis<b.dis;}
class bank{
public:
	int dis;
	int mon;
	int ind;
	static int index;
	bank(int d, int m):dis(d), mon(m), ind((bank::index)++){}
};
int bank::index = 1;
int main(){
//	ifstream cin("BonnieAndClyde.input");
	int ans1=-1, ans2=-1, dis, money = INT_MIN, nBanks, D;
	cin>>nBanks>>D;
	vector<bank> bVec;
	
	for(int i=0; i<nBanks; i++){
		int d;//distance
		int m;//money in the ith bank
		cin>>d>>m;
		bool flag = false;
		for(vector<bank>::iterator it=bVec.begin(); it!= bVec.end(); it++){
			if( d- it->dis < D)
				break;
			if((m + it->mon) > money){
				ans1 = it->ind;
				flag = true;
				money = m + it->mon;
			}
		}
		
		bVec.push_back(bank(d,m));
		if(flag == true)
			ans2 = (bVec.end()-1)->ind;
	}
	cout<<ans1<<" "<<ans2;
	
//	fflush(stdin);
//	getchar();
	return 0;
}*/

