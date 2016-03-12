#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define  INSERT_COST 1
#define  REMOVE_COST 1
#define REPLACE_COST 1
int min(int a, int b, int c){
    return min(a, min(b, c));
}
int _editDistance(const string& s1, const string& s2, const int len1, const int len2, vector<vector<int> >& memo){
    if(memo[len1][len2] == INT_MIN){
        int result;
        if(len1 == 0){
            // if source str s1 is empty, do insert operations len2 times
            result = len2 * INSERT_COST;
        }else if(len2 == 0){
            // if dest str s2 is empty, do remove operation len1 times
            result = len1 * REMOVE_COST;
        }else if(s1[len1-1] == s2[len2-1]){
            result = _editDistance(s1, s2, len1-1, len2-1, memo);
        }else{
            result = min(
                   INSERT_COST + _editDistance(s1, s2, len1, len2-1, memo),
                   REMOVE_COST + _editDistance(s1, s2, len1-1, len2, memo),
                   REPLACE_COST + _editDistance(s1, s2, len1-1, len2-1, memo)
                   );
        }
        memo[len1][len2] = result;
    }
    return memo[len1][len2];
}
//int Solution::minDistance(string s1, string s2){
int minDistance(string s1, string s2){
    vector<vector<int> > memo(1+s1.size(), vector<int>(1+s2.size(), INT_MIN));
    return _editDistance(s1, s2, s1.size(), s2.size(), memo);
}
int main()
{
    cout << minDistance("geeks", "geseks") << endl;
    cout << minDistance("aac", "abac") << endl;
    cout << minDistance("abac", "aac") << endl;
    return 0;
}
