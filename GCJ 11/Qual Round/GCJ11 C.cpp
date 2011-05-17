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
        long long n;
        cin>>n;
        long long c[1000];
        for (int i = 0; i <16; i++)
            c[i] = 0;
        long long sum =0;
        long long axor = 0;
        long long min = 99999999;
        for(long long i=0; i<n; i++)
        {
            cin>>c[i];
            if(c[i] < min)
                min = c[i];
            sum += c[i];
            axor ^= c[i];
        }
        if(axor == 0)
            cout<<"Case #"<<j<<": "<<sum-min<<"\n";
        else
            cout<<"Case #"<<j<<": "<<"NO"<<"\n";
    }
    //getch();
    return 0;
}
