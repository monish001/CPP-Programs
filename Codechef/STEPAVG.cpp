#include<iostream>
/*
Stepping Average
Problem code: STEPAVG
	
ALL SUBMISSIONS
All submissions for this problem are available.

Consider the following weird way of finding the average of N numbers. Take any two of the numbers and replace them with their average; repeat this operation exactly N-1 times. The only remaining number is called the stepping average of the initial set. Note that a set may obviously have different stepping averages depending on our choice for every operation. 

Your task is, given N integers, find a way of performing the operations such that the resulting stepping average is as close to the given integer K as possible. Note that this is a challenge problem: you don't have to find the best possible solution, but the better is your solution the more points you get.
Input

The first line of the input contains an integer T -- the number of test cases (no more than 10). Each test case consists of two lines -- the first of them contains two positive integers N and K (N = 1000, K = 109), the second contains N space-separated positive integers A1..AN (Ai = 109).
Output

The output for each test case should contain exactly N-1 pairs of integers. i-th pair (1-based) x y means that numbers Ax and Ay are chosen at the corresponding operation, their average is written to AN+i, and Ax and Ay can't be used any more. See example explanation for more clarity.
Scoring

Your score for each test case is just the absolute difference between K and your remaining number. Your final score is the average of all test case scores. Your goal is to minimize the final score.
Note that in order for your submission not to be judged as 'Wrong Answer' the following conditions should be satisfied:
your output should contain exactly N-1 pairs of positive integers separated by at least one space for each test case and nothing else;
your output should contain integers strictly less that N+i in the i-th pair (1-based) for each test case;
all integers in your output for each test case should be different.
Example

Input:
1
5 5
9 1 6 3 4

Output:
5 2
4 6
3 1
7 8

Explanation:
We have 5 integers here: 9 1 6 3 4. The first operation is 5 2, so the 6th number becomes (4+1)/2 = 2.5, and the 2nd and the 5th numbers are removed, so we have 9 x 6 3 x 2.5 now (here x means a removed number). Then, 4 6 means that the 7th number becomes (3+2.5)/2 = 2.75, and the 4th and the 6th numbers are removed, resulting in 9 x 6 x x x 2.75. Then, after 3 1 we get x x x x x x 2.75 7.5, and after 7 8 we get x x x x x x x x 5.125. The only number left after the operations is 5.125, so your score for the test case is 0.125.
Test Case Generation

Every official input file contains exactly 10 test cases. In every test case N is equal to 1000, K is chosen randomly and uniformly between 1 and 109, and all Ai are chosen randomly and uniformly between 1 and 109 as well.
*/

#include<ctime>
#include<fstream>
#include<cstdlib>
using namespace std;
#define Ten9 1000000000L

struct number{
	int index;
	int num;
	int def;
};
number a[Ten9];
int compareNumber(const void * a, const void * b)
{
  return ( ((number*)a)->def - ((number*)b)->def );
}
int main(){
    
    ifstream cin("STEPAVG_IN.TXT");
    ofstream cout("STEPAVG_OUT.TXT");
    
	//int ar[2L*Ten9];
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		for(int i=0; i<n; i++){
			cin>>a[i].num;
			a[i].index = i;
			a[i].def = abs(a[i].num-k);
		}
		qsort(a, n, sizeof(number), compareNumber);
		for(int i=0; i<n; i++){
			cout<<a[i].num<<" "<<a[i].index<<" "<<a[i].def<<endl;
		}
		delete[] a;
	}
	
	
//	getchar();
	return 0;
}
