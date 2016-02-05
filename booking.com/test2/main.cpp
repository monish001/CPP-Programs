#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// trim from start
static inline string &ltrim(string &s) {
        s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
        return s;
}
string trimSpaces(string input){
    string output;
    int len = input.size();
    for(int index=0; index<len; index++){
        char curChar = input[index];
        if(curChar != ' '){
            output.push_back(curChar);
        }
    }
    return output;
}
string concatCommaSeparated(vector<string>& words){
    int len = words.size();
    string result;
    if(len == 0){
        return result;
    }
    result = words[0];
    for(int index=1; index<len; index++){
        result += ",";
        result += words[index];
    }
    return result;
}
int main()
{
    //cout<<(int)(' ')<<endl;
    //return 0;
    string inputWord;
    map<string, vector<string> > dictionary;
    int count = 0;
    while (getline(cin, inputWord))
    {
        string wordKey = inputWord;
    //cout<<"Map key before sort:"<<wordKey<<endl;
        sort(wordKey.begin(),wordKey.end());
    //cout<<"Map key  after sort:"<<wordKey<<endl;
    //cout<<"Map key before space triming:"<<wordKey<<endl;
        wordKey = ltrim(wordKey);
    //cout<<"Map key  after space triming:"<<wordKey<<endl;
    //cout<<"Map key:"<<wordKey<<endl;
    //cout<<"\tWord pushed:"<<inputWord<<endl;
        dictionary[wordKey].push_back(inputWord);
//if(++count == 7){break;}
    }
    vector<string> resultList;
    typedef map<string, vector<string> >::iterator it_type;
    for(it_type iterator = dictionary.begin(); iterator != dictionary.end(); iterator++) {
        // iterator->first = key
        // iterator->second = value
        // Repeat if you also want to iterate through the second map.
        vector<string> anagrams = iterator->second;
        //cout<<"Anagrams before sort output:"<<concatCommaSeparated(anagrams)<<endl;
        sort(anagrams.begin(), anagrams.end());
        //cout<<"Anagrams  after sort output:"<<concatCommaSeparated(anagrams)<<endl;
        resultList.push_back(concatCommaSeparated(anagrams));
    }
    sort(resultList.begin(), resultList.end());
    int outputLineCount = resultList.size();
    for(int index=0; index<outputLineCount; index++){
        //cout<<"Final output:"<<endl;
        cout<<resultList[index]<<endl;
    }
    return 0;
}
