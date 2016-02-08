#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <stack>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
bool isPalindrome(const string& input, int startIndex, int endIndex){
    //cout<<"isPalindrome("<<input.substr(startIndex, endIndex-startIndex+1)<<")"<<endl;
    while(startIndex < endIndex){
        if(input[startIndex++] != input[endIndex--]){
            return false;
        }
    }
    return true;
}
//string Solution::longestPalindrome(string input) {
string longestPalindrome(const string input) {
    int maxLen = INT_MIN, maxSi, len = input.size();
    for(int si=0; si<len; si++){
        for(int ei = si; ei<len; ei++){
            //cout<<"In double for loop:"<<si<<" "<<ei<<endl;
            int curLen = ei-si+1;
            bool isPalin = isPalindrome(input, si, ei);
            if(isPalin && curLen > maxLen){
                maxLen = curLen;
                maxSi = si;
            }
        }
    }
    return input.substr(maxSi, maxLen);
}

string longestPalindrome2(const string input) {
//string Solution::longestPalindrome(string input) {
    int maxLen = 1, maxSi=0; // default palindrome of length 1 at index 0.
    int len = input.size();
    vector<vector<bool> > isPalinArr(len, vector<bool>(len, false));
    for(int index=0; index<len; index++){
        isPalinArr[index][index] = true;
    }
    for(int index=1; index<len; index++){
        if(input[index-1] == input[index]){
            isPalinArr[index-1][index] = true;
            if(maxLen < 2){
                maxLen = 2;
                maxSi = index-1;
            }
        }
    }
    for(int size=3; size<=len; size++){
        for(int si=0; si+size<=len; si++){
            int ei = si+size-1;
            if(isPalinArr[si+1][ei-1] && input[si] == input[ei]){
                isPalinArr[si][ei] = true;
                if(size > maxLen){
                    maxLen = size;
                    maxSi = si;
                }
            }
        }
    }
    return input.substr(maxSi, maxLen);
}

int main(){
    cout << longestPalindrome2("aab") << endl;
    cout << longestPalindrome2("aaaabaaa") << endl;
    return 0;
}
