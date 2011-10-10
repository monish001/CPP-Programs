//filename: PARSIN.cpp
//TIME LIMIT EXCEEDED

/* 
Sine Partition Function

Problem code: PARSIN
	
Chef Ciel is participating an arithmetic contest now. Why? Because of the top prize for the contest, a limited edition toaster oven.

She must calculate the values f(M, N, X) of function named sine partition function to be the first place. The sine partition function f(M, N, X) is defined by

Examples are following:

f(1, 3, X) = sin(3X)

f(2, 3, X) = sin(0) sin(3X) + sin(X) sin(2X) + sin(2X) sin(X) + sin(3X) sin(0) = 2 sin(X) sin(2X)

f(3, 1, X) = sin(0) sin(0) sin(X) + sin(0) sin(X) sin(0) + sin(X) sin(0) sin(0) = 0

Ciel is a great chef, however she is not good at arithmetic. For given M, N and X, your work is calculating the value of f(M, N, X).
Input

The first line contains an integer T, the number of test cases. Then T test cases follow. Each test case has 2 integers M, N and a real number X. X has at most two digits after the decimal point.
Output

For each test case, print the value of f(M, N, X). This value must have an absolute or relative error no more than 10^-1. You can safely assume the magnitude of the answer is at most 10^300.
Constraints

1 <= T <= 10
1 <= M <= 30
1 <= N <= 1000000000 (10^9)
0 <= X <= 6.28 < 2*PI
Sample Input

5
1 3 1.57
2 3 0
3 1 2.12
1 1 5
1 30 0.3

Sample Output

-0.99999714638
0
0
-0.959
0.412


*/
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<map>
#include<cstdlib>
#include<cassert>
using namespace std;
double Sin(double t){
	static map<double, double> sine;
	//cout<<"Looking for Sin("<<t<<")\n";
	//getchar();
	if(t==0) return 0;
	map<double, double>::iterator it;
	if((it = sine.find(t)) != sine.end())//found
		return it->second;
	return (sine[t] = sin(t));
}
double computeAns(const short& m/*boxes*/, const int& n/*balls*/, const double& x){
	assert(n>0 && m>0);
	double ans;
	if(m>n || x==0)
		ans = 0;
	else if(m==1)
		ans = Sin(n*x);
	else if(n==1)
		ans = 0;
	else{
		ans=0;
		for(int i=1; i<n; i++){
			ans += Sin(i*x)*computeAns(m-1, n-i, x);
		}
	}
	return ans;
}
int main(){
	int t;
	//cout<<sizeof(int);
	//ifstream cin("PARSIN_in.txt");
	for( cin>>t; t>0; t--){
		short m; int n; double x;
		cin>>m>>n>>x;
		cout<<computeAns(m,n,x)<<"\n";
	}
	//getchar();
	return 0;
}
