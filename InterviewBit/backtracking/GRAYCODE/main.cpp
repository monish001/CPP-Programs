#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
void appendOnePrependedReversedList(vector<int>& nums){
    int len = nums.size();
    for(int index=len-1; index>=0; index--){
        int newNum = len + nums[index];
        nums.push_back(newNum);
    }
}
void toggleBit(int& number, const int bitIndex){
    number = number ^ (1<<bitIndex);
}
vector<int> _grayCode(const int nBits) {
    if(nBits==0){
        return vector<int>(1, 0); // size 1, value 0
    }
    vector<int> subResult = _grayCode(nBits-1);
    appendOnePrependedReversedList(subResult);
    return subResult;
}
//vector<int> Solution::grayCode(int nBits) {
vector<int> grayCode(int nBits) {
    return _grayCode(nBits);
}
void printVec(const vector<int>& vec){
    int len = vec.size();
    for(int index=0; index<len; index++){
        cout<<"\t"<<vec[index];
    }
    cout<<endl;
}
int main()
{
    printVec(grayCode(4));
    return 0;
}
