#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
string joinStrings(const vector<string>& words, char delimiter){
    string result;
    int nWords = words.size();
    if(nWords > 0){
        result = words[0];
    }
    for(int wi=1; wi<nWords; wi++){
        result  = result + string(1, delimiter) + words[wi];
    }
    return result;
}
void _wordBreak(const string input, const int startIndex, vector<string>& wordsSoFar, const vector<string> &dict, vector<string>& result) {
    int nChars = input.size(), nWords = dict.size();
    if(startIndex >= nChars){
        string curResult = joinStrings(wordsSoFar, ' ');
//cout<<"Found match: "<<curResult<<endl;
        result.push_back(curResult);
        return;
    }
    for(int wi=0; wi<nWords; wi++){
        string word = dict[wi], subStr = input.substr(startIndex, word.size());
        if(subStr == word){
//cout<<word<<" "<<subStr<<endl;
            wordsSoFar.push_back(word);
            //dict.erase(dict.begin()+wi);
            _wordBreak(input, startIndex+word.size(), wordsSoFar, dict, result);
            wordsSoFar.pop_back();
            //dict.push_back(word);
        }
    }
}
vector<string> removeDups(vector<string> words){
    vector<string> result;
    int nWords = words.size();
    sort(words.begin(), words.end());
    if(nWords > 0){
        result.push_back(words[0]);
    }
    for(int wi=1; wi<nWords; wi++){
        string word = words[wi];
        if(word != result[result.size()-1]){
            result.push_back(word);
        }
    }
    return result;
}
//vector<string> Solution::wordBreak(string input, vector<string> &dict) {
vector<string> wordBreak(string input, vector<string> &dict) {
    vector<string> result;
    vector<string> wordsSoFar;
    _wordBreak(input, 0, wordsSoFar, removeDups(dict), result);
    sort(result.begin(), result.end());
    return result;
}
void printVec(const vector<string>& vec){
    int len = vec.size();
    for(int index=0; index<len; index++){
        cout<<vec[index]<<endl;
    }
    cout<<endl;
}
int main()
{
    string input = "catsanddog";
    vector<string> vec;
    vec.push_back("cat");
    vec.push_back("cats");
    vec.push_back("and");
    vec.push_back("sand");
    vec.push_back("dog");
    vector<string> result = wordBreak(input, vec);
    printVec(result);

    string input2 = "aaabaaaaab";
    vector<string> vec2;
    vec2.push_back("aabbbaaa");
    vec2.push_back("aaba");
    vec2.push_back("a");
    vec2.push_back("b");
    vec2.push_back("a");
    vec2.push_back("babbbabb");
    vec2.push_back("baaaab");
    result = wordBreak(input2, vec2);
    printVec(result);
    return 0;
}
