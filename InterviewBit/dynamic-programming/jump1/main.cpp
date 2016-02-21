#include <iostream>
#include <vector>

using namespace std;
bool _canJump(vector<char>& canJumpMemo, const vector<int> &nums, const int fromIndex) {
    if(canJumpMemo[fromIndex] == ' '){ // if not calculated already, calculate
        int nNums = nums.size();
        canJumpMemo[fromIndex] = 'f';
        for(int i=nums[fromIndex]; i>=1; i--){
            if(fromIndex+i < nNums && _canJump(canJumpMemo, nums, fromIndex+i)){
cout<<"Setting index "<<fromIndex<<" to 't'"<<endl;
                canJumpMemo[fromIndex] = 't';
                break;
            }
        }
    }
    return canJumpMemo[fromIndex] == 't';
}
//int Solution::canJump(vector<int> &nums) {
int canJump(vector<int> &nums) {
    int nNums = nums.size();
    vector<char> canJumpMemo(nNums, ' '); // space char if not calculated, else 't' or 'f' string if calculated.
    canJumpMemo[nNums-1] = 't';
    return _canJump(canJumpMemo, nums, 0) == true ? 1 : 0;
}
int main()
{
    vector<int> vec;
    vec.push_back(0);

    vector<int> vec1;
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(1);
    vec1.push_back(1);
    vec1.push_back(4);

    vector<int> vec12;
    vec12.push_back(3);
    vec12.push_back(2);
    vec12.push_back(1);
    vec12.push_back(0);
    vec12.push_back(4);

    cout << canJump(vec) << endl;
    cout << canJump(vec1) << endl;
    cout << canJump(vec12) << endl;
    return 0;
}
