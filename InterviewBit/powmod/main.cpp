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

int pow(int x, int n, int d) {
    long long xx = x;
    if(xx==0){return 0;}
    if(xx<0){
        xx += (abs(xx)%d + 1) * d;
    }
    long long result = 1;
    xx%=d;
    while(n>0){
        if(n & 1){ // if power is odd
            result = (result * xx) % d;
        }
        xx = (xx*xx)%d;
        n >>= 1;
    }
    return result;
}
int main()
{
    cout << pow(71045970,41535484,64735492) << endl;
    return 0;
}
