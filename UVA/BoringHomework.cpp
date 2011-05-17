#include<string>
#include<fstream>
#include<list>
#include<iostream>
using namespace std;
void f(...){
	std::cout<<FILENAME_MAX<<" "<<FOPEN_MAX<<" "<<L_tmpnam<<" "<<TMP_MAX;
}
int main(){
	ifstream cin("BoringHomework.txt");
	ofstream cout("BoringHomeworkOut.txt");
	freopen("err.txt", "a+", stderr);
	long long t;
	cin>>t;
	char *a = new char[t];
	a[t-1] = a[t+3];
	f("fghj", "kjkh", 89);
	for(long long i=1; i<=t; i++){
        ;//char
	}
}

