#include<stack>
#include<iostream>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long
#define pii pair<int,int>
vector<string> split(const string& inputPath, const char& delimiter){
    vector<string> parts;
    int strLen = inputPath.size();
    string curString;
    for(int index=0; index<strLen; index++){
        char curChar = inputPath[index];
        if(curChar == delimiter){
            if(!curString.empty()){
                parts.push_back(curString);
                curString = string();
            }
        }else{
            curString.push_back(curChar);
        }
    }
    if(!curString.empty()){
        parts.push_back(curString);
    }
    return parts;
}
stack<string> createSimplifiedStack(const vector<string>& parts){
    stack<string> stk;
    int len = parts.size(), index;
    for(index=0; index<len; index++){
        string curPart = parts[index];
        if(curPart == "."){
            ; // do nothing
        }else if(curPart == ".."){
//cout<<"Stack empty? =  "<<stk.empty()<<"\n";
            if(!stk.empty()){
//cout<<"Found "<<stk.top()<<" to pop out on /../\n";
                stk.pop();
            }
        }else{
            stk.push(curPart);
        }
    }
//cout<<"index value:"<<index<<", length of vec:"<<len<<endl;
    return stk;
}
string mergeParts(stack<string>& stk){
    string result;
    while(!stk.empty()){
        result = "/" + stk.top() + result;
        stk.pop();
    }
    return result.empty() ? "/" : result;
}
void printVec(const vector<string>& vec){
    int len = vec.size();
    for(int index=0; index<len; index++){
        cout<<"\t"<<vec[index];
    }
    cout<<endl;
}
//string Solution::simplifyPath(string inputPath) {
string simplifyPath(string inputPath) {
//cout<<"\n\nInput string: "<<inputPath<<endl;
    vector<string> parts = split(inputPath, '/');
//cout<<"Parts after split:"<<endl;
//printVec(parts);
    stack<string> stk = createSimplifiedStack(parts);
    string result = mergeParts(stk);
//cout<<"Result string: "<<result<<endl;
    return result;
}
int main()
{
    cout << simplifyPath("/./.././ykt/xhp/nka/eyo/blr/emm/xxm/fuv/bjg/./qbd/./../pir/dhu/./../../wrm/grm/ach/jsy/dic/ggz/smq/mhl/./../yte/hou/ucd/vnn/fpf/cnb/ouf/hqq/upz/akr/./pzo/../llb/./tud/olc/zns/fiv/./eeu/fex/rhi/pnm/../../kke/./eng/bow/uvz/jmz/hwb/./././ids/dwj/aqu/erf/./koz/.." ) << endl;
    cout << simplifyPath("/a/b/c/home/..") << endl;
    cout << simplifyPath("/home/") << endl;
    cout << simplifyPath("/a/./b/../../c/") << endl;
    return 0;
}
