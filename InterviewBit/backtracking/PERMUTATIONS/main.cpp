#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int> > result;
void _permute(const vector<int>& nums, vector<int>& remainingNums, vector<int>& curSequence){
    int nRemainingNums = remainingNums.size();
    if(nRemainingNums == 0){
        result.push_back(curSequence);
        return;
    }
    for(int index=0; index<nRemainingNums; index++){
        int curNum = remainingNums[index];
        curSequence.push_back(curNum);
        vector<int> curRemainingNums(remainingNums);
        curRemainingNums.erase(curRemainingNums.begin()+index);
        _permute(nums, curRemainingNums, curSequence);
        curSequence.pop_back();
    }
}
//vector<vector<int> > Solution::permute(vector<int> &nums) {
vector<vector<int> > permute(vector<int> &nums) {
    result = vector<vector<int> >();
    sort(nums.begin(), nums.end());
    vector<int> curSequence = vector<int>();
    _permute(nums, nums, curSequence);
    return result;
}
void printVec(const vector<vector<int> >& vec){
    int len = vec.size();
    for(int index=0; index<len; index++){
        vector<int> aVec = vec[index];
        int innerLen = aVec.size();
        for(int innerIndex=0; innerIndex<innerLen; innerIndex++){
            cout<<aVec[innerIndex]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(1);
    printVec(permute(vec));
    return 0;
}
