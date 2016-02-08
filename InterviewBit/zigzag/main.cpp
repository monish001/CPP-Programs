#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <stack>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
//string Solution::convert(string text, int nRows) {
string convert(string text, int nRows) {
    vector<string> stringList(nRows, string());
    int len = text.size();
    for(int index=0; index<len; ){
        for(int row=0; row<nRows && index<len; row++){
            char curChar = text[index++];
            stringList[row].push_back(curChar);
        }
        for(int row=nRows-2; row>0 && index<len; row--){
            char curChar = text[index++];
            stringList[row].push_back(curChar);
        }
    }
    string result;
    for(int index=0; index<nRows; index++){
        result += stringList[index];
    }
    return result;
}
int main()
{
    cout<<convert("PAYPALISHIRING", 3)<<endl;
    return 0;
}
