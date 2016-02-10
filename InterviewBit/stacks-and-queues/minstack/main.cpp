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

stack<int> stk, minStk;
class MinStack{};
MinStack::MinStack() {
    stk = stack<int>();
    minStk = stack<int>();
}
void MinStack::push(int x) {
    stk.push(x);
    if(minStk.empty() || minStk.top() >= x){
        minStk.push(x);
    }
}
void MinStack::pop(){
    if(!stk.empty()){
        if(stk.top() == minStk.top()){
            minStk.pop();
        }
        stk.pop();
    }
}
int MinStack::top() {
    return stk.empty()?-1:stk.top();
}
int MinStack::getMin() {
    if(minStk.empty()){
        return -1;
    }
    return minStk.top();
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
