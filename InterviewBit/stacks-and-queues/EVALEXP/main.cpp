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
int stringToInt(string str){
    int result = 0, len = str.size();
    bool isNegative = false;
    for(int index=0; index<len; index++){
        char curChar = str[index];
        if(curChar == '-'){
            isNegative = true;
            continue;
        }
        result = result*10+(curChar-'0');
    }
    if(isNegative){
        return -1*result;
    }
    return result;
}
//int Solution::evalRPN(vector<string> &values) {
int evalRPN(vector<string> &values) {
    int nValues = values.size();
    stack<int> stk;
    for(int index=0; index<nValues; index++){
        string curString = values[index];
        int num1, num2, result;

        if(curString == "+"){
            num1 = stk.top(); stk.pop();
            num2 = stk.top(); stk.pop();
            result = num1+num2;
        }else if(curString == "*"){
            num1 = stk.top(); stk.pop();
            num2 = stk.top(); stk.pop();
            result = num1*num2;
        }else if(curString == "/"){
            num1 = stk.top(); stk.pop();
            num2 = stk.top(); stk.pop();
            result = num2/num1;
        }else if(curString == "-"){
            num1 = stk.top(); stk.pop();
            num2 = stk.top(); stk.pop();
            result = num2-num1;
        }else{
            result = stringToInt(curString);
        }
        stk.push(result);
    }
    return stk.top();
}

int main()
{
    vector<string> vec;
    vec.push_back("2");
    vec.push_back("1");
    vec.push_back("+");
    vec.push_back("3");
    vec.push_back("*");

    vector<string> vec2;
    vec2.push_back("4");
    vec2.push_back("13");
    vec2.push_back("5");
    vec2.push_back("/");
    vec2.push_back("+");

    vector<string> vec3;
    vec3.push_back("-4");

    cout << evalRPN(vec) << endl;
    cout << evalRPN(vec2) << endl;
    cout << evalRPN(vec3) << endl;
    return 0;
}
