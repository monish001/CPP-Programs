#include<iostream>
#include<string>
using namespace std;

int main(){
	int t;
	string a[50];
	for(int i=0; i<50; i++){
		a[i] = "12345678901234567890123456789012345678901234567890";
	}
	cin>>t;
	for(int te=0; te<t; te++){
		int nn,mm;
		cin>>nn>>mm;
		for(int n=0; n<nn; n++){
			cin>>a[n];
		}
		int c=0;
		for(int s=1; s<min(mm,nn); s++){
			for(int n=0; n < nn-s; n++){
			for(int m=0; m < mm-s; m++){
				if(a[n][m] == a[n+s][m] && a[n+s][m] == a[n+s][m+s] && a[n+s][m+s] == a[n][m+s] && a[n][m] == a[n][m+s])
					c++;
			}
			}
		}
		cout<<c<<"\n";
	}
	return 0;
}
