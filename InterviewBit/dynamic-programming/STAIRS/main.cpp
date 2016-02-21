#include <iostream>
#include <vector>
using namespace std;

int _climbStairs(vector<int>& nWays, int num){
    if(nWays[num] == INT_MAX){
        nWays[num] = _climbStairs(nWays, num-1) + _climbStairs(nWays, num-2);
    }
    return nWays[num];
}
int Solution::climbStairs(int A) {
    vector<int> nWays(A+1, INT_MAX);
    nWays[1] = 1;
    nWays[2] = 2;
    return _climbStairs(nWays, A);
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
