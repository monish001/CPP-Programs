#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int inputNum;
    int prevNum;
    bool isInit = true;
    while (cin >> inputNum){
        if(isInit){
            isInit = false;
            cout<<inputNum;
            prevNum = inputNum;
        }else{
            int diff = inputNum - prevNum;
            if(diff < -127 || diff > 127){
                cout<<" "<<-128;
            }
            cout<<" "<<diff;
            prevNum = inputNum;
        }
    }
    return 0;
}
