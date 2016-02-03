#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <climits>
using namespace std;
// return eIndex+1 if no right sub tree
string CONSTANT_YES = "YES";
string CONSTANT_NO = "NO";
int getRightSubTreeStartIndex(const vector<int>& nodes, const int sIndex, const int eIndex){
    int curIndex = sIndex+1, rootVal = nodes[sIndex];
    while(curIndex <= eIndex && nodes[curIndex] < rootVal){
        curIndex++;
    }
    return curIndex;
}
int getMin(const vector<int>& nodes, const int sIndex, const int eIndex){
    int minVal = INT_MAX;
    for(int index = sIndex; index<=eIndex; index++){
        minVal = min(minVal, nodes[index]);
    }
    return minVal;
}
string isBst(const vector<int>& nodes, const int sIndex, const int eIndex){
    if(eIndex < sIndex){
        return CONSTANT_YES; // empty tree i guess
    }
    int rightTreeStartIndex = getRightSubTreeStartIndex(nodes, sIndex, eIndex);
    int rootVal = nodes[sIndex];

    if(rightTreeStartIndex <= eIndex){ // if right sub tree exists
        int minValInRightSubTree = getMin(nodes, rightTreeStartIndex, eIndex);
        if(minValInRightSubTree < rootVal){
            return CONSTANT_NO;
        }
    }
    bool isRightBst,
         isLeftBst = isBst(nodes, sIndex + 1, rightTreeStartIndex-1) == CONSTANT_YES;
    if(isLeftBst){
        isRightBst = isBst(nodes, rightTreeStartIndex, eIndex) == CONSTANT_YES;
        if(isRightBst){
            return CONSTANT_YES;
        }
    }
    return CONSTANT_NO;
}
void manageTestCase(){
    int nodeCount;
    cin>>nodeCount;
    vector<int> nodeVals;
    for(int node=0; node<nodeCount; node++){
        int nodeVal;
        cin>>nodeVal;
        nodeVals.push_back(nodeVal);
    }
    cout<<isBst(nodeVals, 0, nodeCount-1)<<endl;
}
int main()
{
    int testCaseCount;
    cin>>testCaseCount;
    for(int testCase=0; testCase<testCaseCount; testCase++){
        manageTestCase();
    }
    return 0;
}
