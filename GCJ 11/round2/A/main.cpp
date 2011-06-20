//#include <iostream>
#include <iomanip>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){

    ifstream cin("Ain.txt");    ofstream cout("Aout.txt");
    short tests; cin>>tests;
    for(short test=1; test <=tests; test++){
        std::cout<<"---------------CASE "<<test<<":---------------\n";
        short s,r;    long x, posSoFar=0; int ns; double runTimeLeft, timeSoFar = 0;
        cin>>x>>s>>r>>runTimeLeft>>ns;
        //long b[1000], e[1000]; short w[1000];
        long b, e; short w;
        for(int n=0; n<ns+1; n++){
            if(n == ns){
                if(e == x)  continue;
                b = e;
                e = x;
                w = 0;
            }else
                cin>>b>>e>>w;
            if(b>posSoFar){
                if(runTimeLeft>0){
                    //Run with speed r till runTimeLeft is not zero OR you reach point b
                    //and update posSoFar and update timeSoFar
                    if(runTimeLeft * r + posSoFar < b){
                        //run for runTimeLeft seconds
                        posSoFar += runTimeLeft*r;
                        timeSoFar += runTimeLeft;
                        runTimeLeft=0;
                    }else{
                        //run till you reach b with speed r
                        double atime = (b-posSoFar)*1.0/r;
                        std::cout<<"1.run time: "<<atime<<"\n";
                        runTimeLeft -= atime;
                        posSoFar = b;
                        timeSoFar += atime;
                    }
                    std::cout<<"Point:"<<b<<"\tTimeSoFar:"<<fixed<<setprecision(9)<<timeSoFar<<"\trunTimeLeft:"<<runTimeLeft<<"\n";
                }
                if (posSoFar < b){
                    //Walk with speed s till you reach b and update posSoFar = b and update timeSoFar
                    double atime = (b-posSoFar)*1.0/s;
                    std::cout<<"2.run time: "<<atime<<"\n";
                    posSoFar = b;
                    timeSoFar += atime;
                    std::cout<<"Point:"<<b<<"\tTimeSoFar:"<<fixed<<setprecision(9)<<timeSoFar<<"\trunTimeLeft:"<<runTimeLeft<<"\n";
                }
            }
            if(runTimeLeft>0){
                //Run with speed r+w till runTimeLeft is not zero OR you reach point e
                //and update posSoFar and update timeSoFar
                if(runTimeLeft * (r+w) < e){
                    //run for runTimeLeft seconds with speed r+w
                    posSoFar += runTimeLeft * (r+w);
                    timeSoFar += runTimeLeft;
                    runTimeLeft = 0;
                }else{
                    //run till you reach e with speed r+w
                    double atime = (e-posSoFar)*1.0/(r+w);
                    std::cout<<"3.run time: "<<e<<"-"<<posSoFar<<"="<<atime<<"\n";
                    runTimeLeft -= atime;
                    posSoFar = e;
                    timeSoFar += atime;
                }
            std::cout<<"Point:"<<b<<"\tTimeSoFar:"<<fixed<<setprecision(9)<<timeSoFar<<"\trunTimeLeft:"<<runTimeLeft<<"\n";
            }
            if (posSoFar < e){
                //Walk with speed s+w till you reach e and update posSoFar = e and update timeSoFar
                double atime = (e-posSoFar)*1.0/(s+w);
                std::cout<<"4.run time: "<<atime<<"\n";
                posSoFar = e;
                timeSoFar += atime;
                std::cout<<"Point:"<<e<<"\tTimeSoFar:"<<fixed<<setprecision(9)<<timeSoFar<<"\trunTimeLeft:"<<runTimeLeft<<"\n";
            }
        }
        cout<<"Case #"<<test<<": "<<fixed<<setprecision(11)<<timeSoFar<<"\n";
    }
    //getch();
    return 0;
}
