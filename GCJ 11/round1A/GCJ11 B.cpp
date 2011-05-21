#include<fstream>
#include<iostream>
#include<string>
#include<vector>

using namespace std;
int check(string str, vector<string> dic){
    return 0;
}
int main(){
    ifstream cin("inB.txt");
    ofstream cout("outB.txt");
    int t,i=1;
    cin>>t;
    for(; i<=t; i++){
        cout<<"Case #"<<i<<":";
        int n,m;
        cin>>n>>m;
        vector<string> dic(n);
        for(int j=0; j<n; j++)
            cin>>dic[j];
        string dic_all = dic[0];
        for(int j=1; j<n; j++)
            dic_all += dic[j];
        std::cout<<dic_all<<"\n";
        for(int j=0; j<m; j++){
            string str; cin>>str;
            int index = check(str, dic);
            cout<<" "<<dic[index];
        }
        cout<<"\n";
    }
    //getch();
    return 0;
}
