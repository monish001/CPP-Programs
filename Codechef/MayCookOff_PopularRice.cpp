//Not tested yet for correctness

#include<map>
#include<fstream>
#include<iostream>
using namespace std;
int main(){
    //ifstream cin("inPopRice");
    //ofstream cout("outPopRice");
    int i,t=0;  cin>>i;
    for(; t<i; t++){
        int n=0, j;
        map<string, int> v;
        map<string, int>::iterator vi;
        for(cin>>j; n<j; n++){
            string s,c;   cin>>s>>c;
            v[s] = (c == "-")?(-1):(1);
        }
        int vt=0;
        for(vi = v.begin(); vi!=v.end(); vi++)
            vt += vi->second;
        cout<<vt<<"\n";
    }
    return 0;
}
