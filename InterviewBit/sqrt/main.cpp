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
int square(int num){
    return num*num;
}
int getFloor(const int sIndex, const int eIndex, const int searchItem){
    if(eIndex < sIndex){
        return 46340; // last perfect square within INT_MAX
    }
    if(searchItem < 2){
        return searchItem; // this is for 0 and 1
    }
    int mIndex = (sIndex + eIndex)/2;
    if(searchItem == square(mIndex)){
        return mIndex;
    }else if(searchItem < square(mIndex) && searchItem > square(mIndex-1)){
        return mIndex-1;
    }else if(searchItem > square(mIndex) && searchItem < square(mIndex+1)){
        return mIndex;
    }else if(searchItem < square(mIndex)){
        return getFloor( sIndex, mIndex-1, searchItem);
    }else{
        return getFloor( mIndex+1, eIndex, searchItem);
    }
}
int main()
{
    int A = 21;
    int len = 46341;
    cout<<sqrt(INT_MAX)<<endl;
    cout<<INT_MAX<<endl;
    int result = getFloor(0, len-1, A);
    cout<<result;
    return 0;
}
