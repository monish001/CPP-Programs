#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
vector<vector<int> > mapVecToVecVec(map<string, vector<int> >& dictionary){
    typedef map<string, vector<int> >::iterator it_type;
    vector<vector<int> > result;
    for(it_type iterator = dictionary.begin(); iterator != dictionary.end(); iterator++) {
        // iterator->first = key
        // iterator->second = value
        // Repeat if you also want to iterate through the second map.
        result.push_back(iterator->second);
    }
    return result;
}
//vector<vector<int> > Solution::anagrams(const vector<string> &inputWords) {
vector<vector<int> > anagrams(const vector<string> &inputWords) {
    int nWords = inputWords.size();
    map<string, vector<int> > mp;
    for(int index=0; index<nWords; index++){
        string word = inputWords[index];
        sort(word.begin(), word.end());
        if(mp.find(word) == mp.end()){
            mp[word] = vector<int>();
        }
        mp[word].push_back(index+1);
    }
    vector<vector<int> > result = mapVecToVecVec(mp);
    return result;
}
void printVecVec(vector<vector<int> > vecVec){
    for(int index=0; index<vecVec.size(); index++){
        for(int innerIndex=0; innerIndex<vecVec[index].size(); innerIndex++){
            cout<<vecVec[index][innerIndex]<<"\t";
        }
        cout<<endl;
    }
}
int main()
{
    vector<string> input;
    input.push_back("cat");
    input.push_back("dog");
    input.push_back("god");
    input.push_back("tca");
    printVecVec(anagrams(input));
    return 0;
}
