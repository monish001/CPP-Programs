#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    int sum, count;
    cin>>sum>>count;
    vector<int> nums;
    for(int index=0; index<count; index++){
        int num; cin>>num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    int startIndex = 0, endIndex = count-1;
    while(endIndex >= startIndex){
        int curSum = nums[startIndex] + nums[endIndex];
        if(curSum == sum){
            return 1;
        }else if(curSum > sum){
            endIndex--;
        }else{
            startIndex++;
        }
    }
    return 0;
}
