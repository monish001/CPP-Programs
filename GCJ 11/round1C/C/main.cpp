//#include <iostream>
#include <iomanip>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;

int GCD(int a,int B )
{
    if( B== 0 )
        return a;
    else
        return GCD(
                   B,a%B );
}
int main(){

    ifstream cin("Cin.txt");    ofstream cout("Cout.txt");
    ll h, l, f[10000];
    int n;
    int te,i=1;    cin>>te;
    for(; i<=te; i++){
        cout<<"Case #"<<i<<": ";
        cin>>n>>l>>h; std::cout<<n<<": ";
        for(int j=0; j<n; j++){
            cin>>f[j];
        }
        bool res = false; ll fin_fre;
        for(ll fr=l; fr<=h; fr++){
            //std::cout<<fr<<" ";
            int j=0;
            for(; j<n; j++){
                if(((fr>f[j])?(fr% f[j]):(f[j] %fr)))
                    break;
            }
            if(j== n){
                res = true;
                fin_fre = fr;
                break;
            }
        }
        if(res == false)
            cout<<"NO\n";
        else
            cout<<fin_fre<<"\n";
        std::cout<<"\n";
    }
    //getch();
    return 0;
}
