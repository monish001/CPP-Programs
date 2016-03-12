#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int _numTrees(const int a, map<int, int>& memo) {
    if(memo.find(a)==memo.end()){
        int result = 0;
        if(a<1){
            result = 1;
        }else{
            for(int i=1; i<=a; i++){
                int nWaysWithRootAsI = 1 * _numTrees(i-1, memo) * _numTrees(a-i, memo);
                result += nWaysWithRootAsI;
            }
        }
        memo[a] = result;
    }
    return memo[a];
}
//int Solution::numTrees(int a) {
int numTrees(int a) {
    map<int, int> memo;
    return _numTrees(a, memo);
}
int main()
{
    cout << numTrees(3)<< endl;
    return 0;
}
