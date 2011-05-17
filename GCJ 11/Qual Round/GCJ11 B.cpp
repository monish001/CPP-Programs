#include<fstream>
#include<iostream>
#include<string>
#include<map>
#include<conio.h>
using namespace std;
int main(){
    ifstream cin("inB.txt");
    ofstream cout("outB.txt");
    int t,i=1;
    cin>>t;
    for(; i<=t; i++){
        cout<<"Case #"<<i<<": [";
        int c_count;
        map<string, char> c;
        for(cin>>c_count; /*cout<<"c : "<<c_count<<"\n", getch(),*/          c_count>0; c_count--){
            char temp[3];
            cin>>temp;
            c[string(temp, 2)] = temp[2];
            char tmp = temp[0]; temp[0] = temp[1]; temp[1]=tmp;
            c[string(temp, 2)] = temp[2];
        }

        int r_count;
        map<string, bool> r;
        for(cin>>r_count; /*cout<<"r : "<<r_count<<"\n", getch(),*/        r_count>0; r_count--){

            char temp[2];
            cin>>temp;
            r[string(temp, 2)] = 1;
            char tmp = temp[0]; temp[0] = temp[1]; temp[1]=tmp;
            r[string(temp, 2)] = 1;

        }

        int n;
        cin>>n;
        char res[100] = {0};
        cin>>res[0];
        int res_top_ind = 0;
        for(;                     /*cout<<n, getch(),*/ n>=2; n--){
            cin>>res[++res_top_ind];
            while(1)            {
                //getch();
                char c_check[2];
                c_check[0] = res[res_top_ind];
                c_check[1] = res[res_top_ind-1];
                char c_check2[2];
                c_check2[0] = res[res_top_ind-1];
                c_check2[1] = res[res_top_ind];

                if( c.count(string(c_check, 2)) || c.count(string(c_check2, 2))){
                    res[--res_top_ind] = c[string(c_check, 2)];
                }else
                    break;
            }

            char r_check[2];
            r_check[1] = res[res_top_ind];
            char r_check2[2];
            r_check2[0] = res[res_top_ind];
            for(int rd=res_top_ind-1; rd>=0; rd--){
//        cout<<"r read";
//        getch();
                r_check[0] = res[rd];
                r_check2[1] = res[rd];
                if( r.count(string(r_check, 2)) || r.count(string(r_check2, 2))){
                    res_top_ind = -1;
                    if(n>2){
                        n--;
                        cin>>res[++res_top_ind];
                    }
                    break;
                }
            }
        }
        for(int i=0; i<res_top_ind; i++)
            cout<<res[i]<<", ";
        if(res_top_ind >= 0)
            cout<<res[res_top_ind];
        cout<<"]\n";
    }
    //getch();
    return 0;
}
