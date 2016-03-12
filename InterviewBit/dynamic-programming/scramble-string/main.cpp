#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
long long getLong(int num){
    return num;
}
long long getHashKey(int n1, int n2, int n3){
    return getLong(n1) + (getLong(n2)<<10) + (getLong(n3)<<20);
}
bool areAnagrams(string s1, string s2){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}
int _isScramble(const string str1, const string str2, const int startIndex1, const int startIndex2, const int subStrLength, map<int, int>& memo) {
    long long key = getHashKey(startIndex1, startIndex2, subStrLength);
    if(memo.find(key)==memo.end()){
        int result = 0;
        if(subStrLength == 1){
            result = str1[startIndex1] == str2[startIndex2] ? 1 : 0;
        }else if(!areAnagrams(str1.substr(startIndex1, subStrLength), str2.substr(startIndex2, subStrLength))){
            result = 0;
        }else{
            for(int i=1; i<subStrLength; i++){
                if(_isScramble(str1, str2, startIndex1, startIndex2, i, memo) && _isScramble(str1, str2, startIndex1+i, startIndex2+i, subStrLength-i, memo)){
                    result = 1;
                    break;
                }
                if(_isScramble(str1, str2, startIndex1, startIndex2 + subStrLength - i, i, memo) && _isScramble(str1, str2, startIndex1+i, startIndex2, subStrLength-i, memo)){
                    result = 1;
                    break;
                }
            }
        }
        memo[key] = result;
cout<<"startIndex1:"<<startIndex1<<", startIndex2:"<<startIndex2<<", subStrLength:"<<subStrLength<<endl;
cout<<"Str1:"<<str1.substr(startIndex1, subStrLength)<<", Str2:"<<str2.substr(startIndex2, subStrLength)<<", key:"<<key<<endl;
    }
    return memo[key];

}
//int Solution::isScramble(const string str1, const string str2) {
int isScramble(const string str1, const string str2) {
    if(str1.size() != str2.size()){
        return 0;
    }
    map<int, int> memo;
    return _isScramble(str1, str2, 0, 0, str1.size(), memo);
}
int main()
{
    cout << isScramble("great", "rgeat") << endl;
    cout << isScramble("great", "rgtae") << endl;
    return 0;
}
