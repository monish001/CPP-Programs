#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

//vector<int> Solution::dNums(vector<int> &nums, int k) {
vector<int> dNums(vector<int> &nums, int k) {
    int nNums = nums.size();
    map<int, int> mp;
    vector<int> result;
    if(k>nNums){
        return result;
    }
    for(int index=0; index<k; index++){
        int num = nums[index];
        if(mp.find(num) == mp.end()){
            mp[num] = 0;
        }
        mp[num]++;
    }

    result.push_back(mp.size());

    for(int ei=k; ei<nNums; ei++){
        int num = nums[ei];
        if(mp.find(num) == mp.end()){
            mp[num] = 0;
        }
        mp[num]++;
        int si = ei-k;
        int prevNum = nums[si];
        int prevNumCount = mp[prevNum];
        if(prevNumCount > 1){
            mp[prevNum]--;
        }else{
            mp.erase(prevNum);
        }
        int mapSize = mp.size();
        result.push_back(mapSize);
    }
    return result;
}
void printVec(const vector<int>& vec){
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<"\t";
    }
}

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(3);
    printVec(dNums(vec, 3));
    return 0;
}
