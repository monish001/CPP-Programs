#include<fstream>
#include<iostream>
#include<string>
#include<map>
#include<conio.h>
using namespace std;

int main(){
    ifstream cin("inC.txt");
    ofstream cout("outC.txt");
    long long t;
    cin>>t;
    for(long long j=1; j<=t; j++){
        cout<<"Case #"<<j<<": "<<"NO"<<"\n";
    }
    //getch();
    return 0;
}
