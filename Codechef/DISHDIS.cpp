//WRONG ANSWER
//filename: DISHDIS.cpp
#include<iostream>
#include<fstream>
#include<cassert>
#include<cstring>
#define MOD (1000000007LL)
using namespace std;
typedef long long ll;
int n;
class poly{
public:
	poly(const int nn):degree(nn){
		coeff = new ll[degree+1];
		for(int i=0; i<=degree; i++)
			coeff[i]=1;
	}
	poly(const int nn, ll * pp):degree(nn), coeff(pp){}
	poly* operator*(poly& p2){
		int deg2 = p2.getDegree();
		ll *p = new ll[this->degree + deg2 + 1];
		for(int i=0; i<this->degree + deg2 + 1; i++)
			p[i]=0;
		
		for(int i=0; i<= this->degree; i++){
			for(int j=0; j<=deg2; j++){
				if(i+j > n) continue;
				p[i+j] += getCoeff(i) * p2.getCoeff(j);
				p[i+j] %= MOD;
			}
		}
		return (new poly(degree + deg2, p));
	}
	ll getCoeff(int n){
		if(n<=degree && n>=0);
			return coeff[n];
		return 0;
	}
	int getDegree(){return degree;}
	void print(){
		for(int i=0; i<=degree; i++)
			cout<<coeff[i]<<" ";
		cout<<"\n";
	}
	~poly(){
		delete[] coeff;
	}
private:
	int degree;
	ll *coeff;
};
int main(){
	int t;
	//ifstream cin("in.txt");
	for(cin>>t ; t>0; t--){
		int min, cap;
		//int n;//num of dishes
		int m;//#chefs
		cin>>n>>m;
		poly *ans = new poly(0);
		bool isPossible=true;
		for(int mm=0; mm<m; mm++){
			cin>>min>>cap;
			cap -= min;
			n -= min;
			if(n<0 || cap <0){
				isPossible = false;
				break;
			}
			poly curChef(cap);
			poly *tmp = curChef * *ans;
			delete ans;
			ans = tmp;
		}
		cout<< ((isPossible)?((ans->getCoeff(n))%MOD):(0));
		cout<<"\n";
		delete ans;
	}
	/*
	ll *l1 = new ll[3];
	l1[0]=2;
	l1[1] = 0;
	l1[2] = 3;
	poly p1(2, l1);
	p1.print();
	ll *l2 = new ll[4];
	l2[0] = 1;
	l2[1] = 2;
	l2[2] = 3;
	l2[3] = 0;
	poly p2(3, l2);
	p2.print();
	(p1*p2)->print();*/
	//getchar();
	return 0;
}
