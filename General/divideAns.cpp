/*
Question:
Write a program which gives a numerator and a denominator, prints the fractional value in a special format. eg. Numerator: 1, Denominator: 3. So Num/Denom = 0.3333333333, but output should be .(3) similarly 0.123123 as .(123) also 0.34232323 as 0.34(23)
*/
#include<list>
#include<iostream>
#include<cstdlib>
using namespace std;

list<char>::iterator find(list<char> & l,char c){
	list<char>::iterator it=l.begin();
	for(;it!=l.end();it++)
		if(*it==c)
			break;
	return it;
}
class Divide{
	list<char> ans;
	int num,den;
	public:
	Divide(int num, int den)/*:num(n),den(d)*/{
		this->num = num; this->den = den;
        char temp[10];
		char *p=itoa(num/den,temp,10);
		for(;*p;p++)
			ans.push_back(*p);
		ans.push_back('.');
		list<char> tmp;
		num%=den;
		list<char>::iterator it;
		for(int counter=0;num!=0 || counter<2; counter++){
			num*=10;
			if((it=find(tmp, num/den+'0'))!=tmp.end())
				break;
			tmp.push_back(num/den+'0');
			num%=den;
		}
		tmp.insert(it, '(');
		tmp.insert(tmp.end(), ')');
		tmp.insert(tmp.end(), '\0');
		ans.splice(ans.end(), tmp, tmp.begin(), tmp.end());//append tmp after ans
	}
	void printAns(){
		list<char>::iterator it=ans.begin();
		for(;it!=ans.end();it++)
			cout<<*it;
		cout<<"\n";
	}
};
int main(){
	Divide das(1000, 28);
	das.printAns();
	getchar();
	return 0;
}
