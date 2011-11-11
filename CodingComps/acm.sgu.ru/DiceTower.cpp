//filetype: DiceTower.cpp
//Status: Wrong answer on test 20
/* Question: http://acm.sgu.ru/problem.php?contest=38&problem=D
D. Dice Tower
Time limit per test: 2 second(s)
Memory limit: 262144 kilobytes
input: standard
output: standard

Polycarp loves not only to play games, but to invent ones as well. He has recently been presented with a board game which also had lots of dice. Polycarp quickly noticed an interesting phenomenon: the sum of dots on any two opposite sides equals 7.


The dice

An unfolded die
Polycarp invented the following game. He asks somebody to tell a positive integer n and then he constructs a dice tower putting the dice one on another one. A tower is constructed like that: Polycarp puts a die on the table and then (if he wants) he adds more dice, each time stacking a new die on the top of the tower. The dice in the tower are aligned by their edges so that they form a perfect rectangular parallelepiped. The parallelepiped's height equals the number of dice in the tower and two other dimensions equal 1 (if we accept that a die's side is equal to 1).


An example of a tower whose height equals 3
Polycarp's aim is to build a tower of minimum height given that the sum of points on all its outer surface should equal the given number n (outer surface: the side surface, the top and bottom faces).

Write a program that would determine the minimum number of dice in the required tower by the given number n. Polycarp can construct any towers whose height equals 1 or more.

Input
The only input line contains integer n (1 = n = 106).

Output
Print the only integer — the number of dice in the required tower. If no such tower exists, print

-1

.

Example(s)

sample input

	

sample output

50

	

3


sample input

	

sample output

7

	

-1


sample input

	

sample output

32

	

2




Online Contester Team © 2002 - 2010. All rights reserved.

*/
#include<iostream>
#include<map>
#include<climits>
#include<cstdarg>
#include<algorithm>
using namespace std;

int minGeneral(int num, ...){
	va_list list;
	int min = INT_MAX;
	va_start(list, num);
	for(int i=0; i<num; i++){
		int tmp = va_arg(list, int);
		if(tmp < min)
			min = tmp;
	}
	return min;
}
map<int//sum
	,int//num of dices
	> mp;
int getDices(int sum){
	if(sum == 0)
        return 0;
    else if(sum<15)
		return INT_MAX/2;// Infinite number of dices are required
	else if(sum < 21){
		return 1;
	}else if(sum< 30){
		return INT_MAX/2;
	}
	if(mp.find(sum) != mp.end()){//if already computed
		return mp[sum];
	}
	int ans;
	{
		ans = INT_MAX/2;
		for(int i=30; i<=40; i++){
			int tmp = getDices(sum-i)+2;
			if(ans > tmp)
				ans = tmp;
		}
	}
	mp[sum] = ans;
	return ans;
}
int main(){
		
	int t;
	cin>>t;
	int ans=999;
	if(t<21)
		ans = -1;
	else if(t == 21)
		ans = 1;
	else{
		ans = getDices(t);
		if(ans <=0 || ans >= (INT_MAX/2) )
			ans = -1;
	}
//	cout<<(INT_MAX<<1)<<"\n";
	cout<<ans;
	
	fflush(stdin);
	getchar();
	return 0;
}

