//#include <iostream>
#include <iomanip>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){

        ifstream cin("Ain.txt");    ofstream cout("Aout.txt");
    string t[50];
    for(int j=0; j<50; j++)
        t[j] = "12345678901234567890123456789012345678901234567890";
    int te,i=1;    cin>>te;
    for(; i<=te; i++){
        cout<<"Case #"<<i<<":\n";
        int r, c; bool flag = true;
        cin>>r>>c;
        for(int j =0; j<r; j++){//each row
            for(int k =0; k<c; k++){//each col
                cin >> t[j][k];
            }
        }
        for(int j =0; j<r-1; j++){//each row
            for(int k =0; k<c-1; k++){//each col
                if(t[j][k] == '#' && t[j][k+1] == '#' && t[j+1][k+1] == '#' && t[j+1][k] == '#'){
                    t[j][k] = '/';  t[j][k+1] = '\\'; t[j+1][k+1] = '/'; t[j+1][k] = '\\';
                }else if(t[j][k] == '#'){
                    flag = false;
                    break;
                }
            }
            if(flag == false)
                break;
        }

        if(flag == true){
            for(int j=0; j<r; j++)
                if(t[j][c-1] == '#' || t[r-1][j] == '#'){
                    flag = false;
                    break;
                }
        }

        if(flag == false)
            cout<<"Impossible\n";
        else{
            for(int j =0; j<r; j++){//each row
                for(int k =0; k<c; k++){//each col
                    cout<<t[j][k];
                }
                cout<<"\n";
            }
        }

    }
    //getch();
    return 0;
}
