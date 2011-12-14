/*
Running Online Link: https://ideone.com/Eg6Ka

http://www.spoj.pl/problems/HOTELS/

SPOJ Problem Set (classical)

9861. Hotels Along the Croatian Coast

Problem code: HOTELS


 
There are N hotels along the beautiful Adriatic coast. Each hotel has its value in Euros.

Sroljo has won M Euros on the lottery. Now he wants to buy a sequence of consecutive hotels, such that the sum of the values of these consecutive hotels is as great as possible - but not greater than M.

You are to calculate this greatest possible total value.

Input

In the first line of the input there are integers N and M (1 = N = 300 000, 1 = M < 231).

In the next line there are N natural numbers less than 106, representing the hotel values in the order they lie along the coast.

Output

Print the required number (it will be greater than 0 in all of the test data).

Example

input
5 12
2 1 3 4 5
output
12
input
4 9
7 3 5 6
output
8
*/

#include<iostream>
#include<deque>
using namespace std;
int main(){
	int n, m, sum=0, val;
	cin>>n>>m;
	deque<int> d;
	int localSum=0;
	for(int i=0; i<n; i++){
		cin>>val;
		d.push_back(val);
		localSum+=val;
		while(localSum>m){
			localSum-=d[0];
			d.pop_front();
		}
		sum = max(sum, localSum);
	}
	cout<<sum;
	return 0;
}