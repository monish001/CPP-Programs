#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstring>
using namespace std;
void swapCharsInString(string& str, const int index1, const int index2){
    int len = str.size();
    if(index1 < len && index2 < len){
        char tmp = str[index1];
        str[index1] = str[index2];
        str[index2] = tmp;
    }
}
void reverseStr(string& str){
    int len = str.size();
    for(int index=0; index<len/2; index++){
        swapCharsInString(str, index, len-index-1);
    }
}
string addBinary(string A, string B) {
//string Solution::addBinary(string A, string B) {
    if(A.empty()){
        return B;
    }
    if(B.empty()){
        return A;
    }
    string resultStr;
    int prevCarry = 0;
    int l1 = A.size(), l2 = B.size();
    for(int i1 = l1-1, i2 = l2-1; i1>=0 || i2>=0; i1--, i2--){
        int val1 = (i1 < 0) ? 0 : A[i1] - '0';
        int val2 = (i2 < 0) ? 0 : B[i2] - '0';

        int result, resultCarry;
        result = val1 ^ val2 ^ prevCarry;
        resultCarry = val1 + val2 + prevCarry > 1 ? 1 : 0;

        resultStr.push_back((char)(result + '0'));
        prevCarry = resultCarry;
    }
    if(prevCarry){
        resultStr.push_back('1');
    }

    reverseStr(resultStr);

    return resultStr;
}


int main()
{
    cout << addBinary("100", "10") << endl;
    cout << addBinary("110", "") << endl;
    cout << addBinary("", "110") << endl;
    cout << addBinary("10", "100") << endl;
    cout << addBinary("", "") << endl;
    cout << addBinary("111", "111") << endl;
    return 0;
}
