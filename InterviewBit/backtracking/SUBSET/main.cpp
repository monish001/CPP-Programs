#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int> > result;
void _subsets(const vector<int>& nums, const int startIndex, vector<int> setSoFar){
    int nNums = nums.size();
    if(nNums == startIndex){
        result.push_back(setSoFar);
        return;
    }
    _subsets(nums, startIndex+1, setSoFar);
    setSoFar.push_back(nums[startIndex]);
    _subsets(nums, startIndex+1, setSoFar);
    setSoFar.pop_back();
}
bool compareVecInts(const vector<int>& vec1, const vector<int>& vec2){
    int ind1=0, ind2=0, len1=vec1.size(), len2 = vec2.size();
    for(; ind1<len1 && ind2<len2; ind1++, ind2++){
        if(vec1[ind1] != vec2[ind2]){
            return vec1[ind1] < vec2[ind2];
        }
    }
    if(ind1 == len1){
        return true;
    }
    return false;
}
//vector<vector<int> > Solution::subsets(vector<int> &A) {
vector<vector<int> > subsets(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    result = vector<vector<int> >();
    _subsets(nums, 0, vector<int>());
    sort(result.begin(), result.end(), compareVecInts);
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
    printVec(subsets(vec));
    return 0;
}
