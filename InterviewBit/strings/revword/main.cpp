#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> split(const string& inputStr, char delimiter){
    vector<string> result;
    int nChars = inputStr.size(), index = 0;
    string curStr;
    while(index < nChars){
        char curChar = inputStr[index];
        if(curChar == delimiter){
            if(curStr != ""){
                result.push_back(curStr);
                curStr = "";
            }
        }else{
            curStr.push_back(curChar);
        }
        index++;
    }
    if(curStr != ""){
        result.push_back(curStr);
    }
    return result;
}
string reverseWord(const string& inputStr){
    string result;
    int nChars = inputStr.size();
    for(int i=nChars-1; i>=0; i--){
        char curChar = inputStr[i];
        result.push_back(curChar);
    }
    return result;
}
string join(const vector<string>& words){
    int nWords = words.size();
    string result;
    for(int i=0; i<nWords-1; i++){
        result  = result + words[i] + " ";
    }
    if(nWords>0){
        result += words[nWords-1];
    }
    return result;
}
//void Solution::reverseWords(string &inputStr) {
string reverseWords(string inputStr) {
    inputStr = reverseWord(inputStr);
    vector<string> words = split(inputStr, ' ');
    for(int i=words.size()-1; i>=0; i--){
        words[i] = reverseWord(words[i]);
    }
    string result = join(words);
    inputStr = result;
    return result;
}
int main()
{
    cout << reverseWords("the sky is blue") << endl;
    cout << reverseWords("   the sky is blue") << endl;
    cout << reverseWords("the sky is blue   ") << endl;
    cout << reverseWords("   the sky is blue   ") << endl;
    return 0;
}
