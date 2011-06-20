//WRONG WRONG WRONG 
#include<string>
#include<cmath>
//#include<>
using namespace std;

class LuckyRemainder{
	public: int getLuckyRemainder(string X){
		long long n =0;
		for(int i=X.length()-1; i>=0; i--){
			for(int j=X.length()-1; j<=i; j--){
				n += nCr(j,i);
			}
			if(i)
				n *= 10;
		}
		return n%9;
	}
/*WRONG	public: int getLuckyRemainder(string X){
		long long n =0;
		for(int i=0; i<X.length(); i++)
			n += pow(2, i)*(X[i]-'0');
			n %= 9;
		return n;
	}*/
};
