#include<iostream>
using namespace std;

/*Question 8. Write an algorithm find the minimal positive integer number Q so that the product of digits of Q is exactly equal to N. Input contains the single integer number N(0<=N<=109). Program should output only number Q. If such a number does not exist print -1. For example if you input 10 the output is 25.
Test case:
	for(int i=20; i<=30; i++)
		cout<<i<<":"<<find(i)<<"\n";
Output:
	20:45
	21:37
	22:-1
	23:-1
	24:38
	25:55
	26:-1
	27:39
	28:47
	29:-1
	30:56
*/
int divisor(int N){
	for(int i=9; i>1; i--){
		if(N%i==0)
			return i;
	}
	return -1;
}
int find(int N){
    if(N<=9)
        return N;
	int q=divisor(N);
	if(q==-1)
        return -1;
	int temp = find(N/q);
	if(temp == -1)
		return -1;
	q += temp*10;
	return q;
}