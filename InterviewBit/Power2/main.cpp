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
bool isPower2(int A){
    vector<int> nums;
    //nums.push_back(1);
    if(A==1){return true;}
    int MAX_p = 30;
    for(int p=2; p<=MAX_p; p++){
        // as A**P < 2**31, max_A as follow
        int MAX_a = pow(2, 31.0/p);
        cout<<"MAX_a:"<<MAX_a<<" for p:"<<p<<endl;
        for(int a=2; a<=MAX_a; a++){
            long val = pow(a, p);
            //nums.push_back();
            if(val == A) return true;
        }
    }
    return false;
}
int main(){
    cout<<"Int:"<<sizeof(int)<<endl;
    cout<<"Long:"<<sizeof(long)<<endl;
    cout<<"Long long"<<sizeof(long long)<<endl;
    cout<<isPower2(536870912);
    return 0;
}
