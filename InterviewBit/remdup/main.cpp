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

//int Solution::removeDuplicates(vector<int> &nums) {
int removeDuplicates(vector<int> &nums) {
    int len = nums.size();
    if(len <= 1){
        return len;
    }
    int uniqueTillIndex = 0;
    for(int index=1; index<len; index++){
        if(nums[index] != nums[index-1]){
            nums[uniqueTillIndex+1] = nums[index];
            uniqueTillIndex++;
        }
    }
    int newSize = uniqueTillIndex+1;
    nums.resize(newSize);
    return newSize;
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(4);

    vector<int> arr2;
    arr2.push_back(0);
    cout << removeDuplicates(arr2) << endl;
    return 0;
}
