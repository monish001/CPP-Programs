#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class TrieNode{
    const int NODE_RANGE = 26; // a-z
    char data;
    bool isWord;
    int wordCount;
    vector<TrieNode*> next;//(26, NULL);
public:
    TrieNode(char val) : data(val), isWord(false), wordCount(0){
        next.resize(NODE_RANGE, NULL);
    }
    void setIsWord(bool val){
        isWord = val;
    }
    // returns the next node that represents charVal. Created the node is not existing.
    TrieNode* getNext(char charVal){ // index from 0 to 25
        int index = charVal - 'a';
        if(next[index] == NULL){
            next[index] = new TrieNode(charVal);
        }
        return next[index];
    }
    void incWordCount(){
        wordCount++;
    }
    int getWordCount(){
        return wordCount;
    }
    ~TrieNode(){}
};
class Trie{
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode('?');
    }
    void push(string word){
        int len = word.size();
        TrieNode* curNode = root;
        curNode->incWordCount();
        for(int i=0; i<len; i++){
            char curChar = word[i];
            curNode = curNode->getNext(curChar);
            curNode->incWordCount();
        }
        curNode->setIsWord(true);
    }
    string getPrefix(string word){
        int len = word.size();
        TrieNode* curNode = root;
        string result;
        for(int i=0; i<len; i++){
            char curChar = word[i];
            curNode = curNode->getNext(curChar);
            result.push_back(curChar);
            if(curNode->getWordCount() == 1){
                break;
            }
        }
        return result;
    }
    ~Trie(){
        //TODO clean up memory for each node of tree
    }
};
//vector<string> Solution::prefix(vector<string> &words) {
vector<string> prefix(vector<string> &words) {
    int nWords = words.size();
    vector<string> result;
    Trie tree;
    for(int i=0; i<nWords; i++){
        string word = words[i];
        tree.push(word);
    }
    for(int i=0; i<nWords; i++){
        string word = words[i];
        string prefix = tree.getPrefix(word);
        result.push_back(prefix);
    }
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
    vector<string> input;
    input.push_back("zebra");
    input.push_back("dog");
    input.push_back("duck");
    input.push_back("dove");
    vector<string> result = prefix(input);
    printVec(result);
    return 0;
}
