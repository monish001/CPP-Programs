#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
using namespace std;
vector<string> getPatternList(){
    vector<string> patternList;
    patternList.push_back("AB");
    patternList.push_back("BA");
    patternList.push_back("CB");
    patternList.push_back("BC");
    patternList.push_back("AA");
    patternList.push_back("CC");
    return patternList;
}
map<string, string> getRules(){
    map<string, string> rules;
    rules["AB"] = "AA";
    rules["BA"] = "AA";
    rules["CB"] = "CC";
    rules["BC"] = "CC";
    rules["AA"] = "A";
    rules["CC"] = "C";
    return rules;
}
string getTwoLetterStrAtIndex(string str, int index){
    int nChars = str.size();
    string result;
    if(index+1 >= nChars){
        return result;
    }
    result.push_back(str[index]);
    result.push_back(str[index+1]);
    return result;
}
vector<int> findPatterns(string inputStr, const map<string, string>& rules){
    int nChars = inputStr.size();
    vector<int> result;
    for(int i=0; i<nChars-1; i++){
        string curTwoLetterStr = getTwoLetterStrAtIndex(inputStr, i);
        if(rules.find(curTwoLetterStr) != rules.end()){
            result.push_back(i);
        }
    }
    return result;
}
string solution(string S) {
    string result, inputString = string(S);
    map<string, string> rules = getRules();
    int nChars = inputString.size();
    for(int i=0; i<nChars; i++){
        char curChar = inputString[i];
        string curTwoLetterStr = getTwoLetterStrAtIndex(inputString, i);
        if(rules.find(curTwoLetterStr) != rules.end()){
            string replacement = rules[curTwoLetterStr];
            if(replacement.size() == 2){
                inputString[i] = replacement[0];
                inputString[i+1] = replacement[1];
            }else{ // replacement size is one
                inputString[i+1] = replacement[0];
            }
            i--; // parse again
        }else{
            result.push_back(curChar);
        }
    }
    return result;
}
int main()
{
    cout << solution("A") << endl;
    cout << solution("ABBCC") << endl;
    cout << solution("AAAA") << endl;
    cout << solution("AA") << endl;
    return 0;
}
