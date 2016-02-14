#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <stack>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

//int Solution::threeSumClosest(vector<int> &nums, int sum) {
int threeSumClosest(vector<int> &nums, int sum) {
    int len = nums.size();
    int minDiff = INT_MAX, sumForMinDiff;
    sort(nums.begin(), nums.end());
    for(int index1=0; index1<len; index1++){
        int index2=0, index3 = len-1;
        while(index2<index3){
            if(index1 == index2){
                index2++;
                continue;
            }
            if(index3==index1){
                index3--;
                continue;
            }
            int curSum = nums[index1] + nums[index2] + nums[index3];
            int curDiff = abs(sum - curSum);
            if(curDiff < minDiff){
                minDiff = curDiff;
                sumForMinDiff = curSum;
            }
            if(sum > curSum){
                index2++;
            }else if(sum < curSum){
                index3--;
            }else{
                break;
            }
        }
    }
    return sumForMinDiff;
}

int main()
{
    vector<int> arr;
    arr.push_back(-1);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(-4);
    cout << threeSumClosest(arr, 1) << endl;
    return 0;
}
