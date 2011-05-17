#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ifstream cin("inA.txt");
    ofstream cout("outA.txt");
    int t,i=1;
    cin>>t;
    for(; i<=t; i++){
        int n, btime=0, otime=0, blevel=1, olevel=1;
        char prev = 'a';
        for(cin>>n; n>0; n--){
            char ob;
            int li;
            cin>>ob>>li;
            if(ob == 'O'){
                otime += 1 + abs(olevel - li);
                if(otime > btime)
                    ;
                else
                    otime = btime+1;
                olevel = li;
            }else{
                btime += 1+ abs(blevel - li);
                if(btime > otime)
                    ;
                else
                    btime = otime + 1;
                blevel = li;
            }
            prev = ob;
        }
        cout<<"Case #"<<i<<": "<<max(otime, btime)<<"\n";
    }
}
