//#include <iostream>
#include <iomanip>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
char val[100][100];
int match[100], win[100];
double wp[100], o[100], oo[100];
using namespace std;
int main(){
    ifstream cin("Ain.txt");
    ofstream cout("Aout.txt");
    int t,i=1;
    cin>>t;
    for(; i<=t; i++){
        cout<<"Case #"<<i<<":\n";
        int n;
        cin>>n;
        std::cout<<"\n\nwp : ";
        for(int j=0; j<n; j++){
            wp[j] = 0.0; o[j]=0.0; oo[j] =0.0; match[j]=0; win[j]=0;
            for(int k=0; k<n; k++){
                cin>>val[j][k];
                //std::cout<<val[j][k];
                if(val[j][k] == '1')
                    match[j]++, win[j]++;
                else if(val[j][k] == '0')
                    match[j]++;
            }
            wp[j] = (1.0*win[j])/match[j];

            //std::cout<<"\n";
            std::cout<<wp[j]<<" ";
        }

        std::cout<<"\nowp: ";
        for(int j=0; j<n; j++){
            int count =0;
            for(int k=0; k<n; k++){
                if(val[j][k] == '.')
                    continue;
                count++;
                o[j] += (win[k]-val[k][j]+'0')*1.0/(match[k]-1);
            }
            o[j] /= count;
            std::cout<<o[j]<<" ";
        }

        std::cout<<"\noowp: ";
        for(int j=0; j<n; j++){
            int count=0;
            for(int k=0; k<n; k++){
                if(val[j][k] == '.')
                    continue;
                count++;
                oo[j] += o[k];
            }
            oo[j] = oo[j]*1.0/  count;
            std::cout<<oo[j]<<" ";
        }

        for(int j=0; j<n; j++)
            cout<<setprecision(12)<<0.25*wp[j] + 0.5 * o[j] + .25 * oo[j]<<"\n";
    }
    //getch();
    return 0;
}
