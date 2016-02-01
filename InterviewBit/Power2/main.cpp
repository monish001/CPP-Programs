#include<iostream>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include <climits>
#include <cmath>
using namespace std;

#define ll long long
#define pii pair<int,int>

vector<int> vec(1<<26, 0);//1<<26 same as 2 raise to power 26
void setBitVec(vector<int>& vec, int index, bool value){
    int vecIndex = index/32;
    int num = vec[vecIndex];
    int mask = 1<<(31-index%32);
    vec[vecIndex] = mask | num;
}
bool getBitVec(vector<int>& vec, int index){
    int num = vec[index/32];
    int mask = 1<<(31-index%32);
    return mask & num;
}
bool init = false;
long A_MAX = ((long)1)<<31;
bool isPower1(int A){
    if(init==false){
        int sqrtAmax = sqrt(A_MAX);
        setBitVec(vec, 1, true);
        for(int a=2; a<=sqrtAmax; a++){
            for(int p=2;; p++){
                cout<<"a:"<<a<<"\tp:"<<p<<endl;
                long val = pow(a,p);
                if(val>A_MAX){
                    break;
                }
                if(A==val){
                    setBitVec(vec, val, true);
                }
            }
        }
        init = true;
    }
    return getBitVec(vec, A);
}
int main(){
cout<<"Int:"<<sizeof(int)<<endl;
cout<<"Long:"<<sizeof(long)<<endl;
cout<<"Long long"<<sizeof(long long)<<endl;
    cout<<isPower1(26);
    return 0;
}
