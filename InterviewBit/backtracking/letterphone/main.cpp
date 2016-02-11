#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
vector<string> result;
vector<string> keypadMap;
void initKeypadMap(){
    keypadMap.push_back("0");
    keypadMap.push_back("1");
    keypadMap.push_back("abc");
    keypadMap.push_back("def");
    keypadMap.push_back("ghi");
    keypadMap.push_back("jkl");
    keypadMap.push_back("mno");
    keypadMap.push_back("pqrs");
    keypadMap.push_back("tuv");
    keypadMap.push_back("wxyz");
}
void _letterCombinations(const string inputDigits, const int startIndex, string resultSoFar){
    int len = inputDigits.size();
    if(startIndex == len){
        result.push_back(resultSoFar);
        return;
    }
    string validChars = keypadMap[inputDigits[startIndex]-'0'];
    int validCharsCount = validChars.size();
    for(int index=0; index<validCharsCount; index++){
        resultSoFar[startIndex] = validChars[index];
        _letterCombinations(inputDigits, startIndex+1, resultSoFar);
    }
    resultSoFar[startIndex] = '-';
}

//vector<string> Solution::letterCombinations(string inputDigits) {
vector<string> letterCombinations(const string inputDigits) {
    initKeypadMap();
    result = vector<string>();
    _letterCombinations(inputDigits, 0, string(inputDigits.size(), '-'));
    sort(result.begin(), result.end());
    return result;
}
void printVec(const vector<string>& vec){
    int len = vec.size();
    for(int index=0; index<len; index++){
        cout<<"\t"<<vec[index];
    }
    cout<<endl;
}
int main()
{
    printVec(letterCombinations("23"));
    return 0;
}
