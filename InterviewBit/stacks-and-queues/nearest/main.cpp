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
int lookBackSmallerNumber(stack<int>& inputStack){
    stack<int> tmpStack;
    int result = -1, number = inputStack.top();
    inputStack.pop();
    tmpStack.push(number);
    while(!inputStack.empty()){
        int curNum = inputStack.top();
        if(curNum < number){
            result = curNum;
            break;
        }else{
            inputStack.pop();
            //tmpStack.push(curNum);
        }
    }
    while(!tmpStack.empty()){
        inputStack.push(tmpStack.top());
        tmpStack.pop();
    }
    return result;
}
//vector<int> Solution::prevSmaller(vector<int> &numbers) {
vector<int> prevSmaller(vector<int> &numbers) {
    int len = numbers.size();
    stack<int> stk;
    vector<int> result;
    for(int index=0; index<len; index++){
        stk.push(numbers[index]);
        result.push_back(lookBackSmallerNumber(stk));
    }
    return result;
}
void printVec(const vector<int>& vec){
    int len = vec.size();
    for(int index=0; index<len; index++){
        cout<<"\t"<<vec[index];
    }
    cout<<endl;
}

int main()
{
    vector<int> vec;
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(2);
    vec.push_back(10);

    vector<int> vec2;
    vec2.push_back(3);
    vec2.push_back(2);
    vec2.push_back(1);

    vector<int> result = prevSmaller(vec2);
    printVec(result);
    return 0;
}
