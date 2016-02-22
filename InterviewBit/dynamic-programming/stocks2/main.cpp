#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int _maxProfit(const vector<int> &prices, const int endIndex) {
    int nDays = endIndex+1;
    int profitSoFar = 0;
    if(nDays < 2){
        return profitSoFar;
    }
    int op1 = _maxProfit(prices, endIndex-1);
    int op2 = op1 + prices[endIndex] - prices[endIndex-1];
    return max(op1, op2);
}
//int Solution::maxProfit(const vector<int> &prices) {
int maxProfit(const vector<int> &prices) {
    return _maxProfit(prices, prices.size()-1);
}
int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    cout << maxProfit(vec) << endl;
    return 0;
}
