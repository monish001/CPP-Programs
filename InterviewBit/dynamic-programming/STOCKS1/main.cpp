#include <iostream>
#include <vector>

using namespace std;

//int Solution::maxProfit(const vector<int> &arr) {
int maxProfit(const vector<int> &arr) {
    int result = 0, nNums = arr.size();
    if(nNums < 2){
        return 0;
    }
    int minSoFar = arr[0], bestSP = arr[0], bestBP = arr[0];
    for(int i=1; i<nNums; i++){
        int num = arr[i];
        if(bestSP - bestBP < num-minSoFar){
            bestBP = minSoFar;
            bestSP = num;
        }
        minSoFar = min(minSoFar, num);
    }
    return bestSP - bestBP;
}
int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(-1);
    cout << maxProfit(vec) << endl;
    return 0;
}
