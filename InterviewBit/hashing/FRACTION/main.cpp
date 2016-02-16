#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
string toString(long long number){
    string result;
    do{
        result = string(1, number%10 + '0') + result;
        number /= 10;
    }while(number);
    return result;
}
string insertOpenBraceBeforeN(const int inputIndex, const string& input){
    string result;
    int len = input.size();
    for(int index=0; index<len; index++){
        if(inputIndex == index){
            result.push_back('(');
        }
        char curChar = input[index];
        result.push_back(curChar);
    }
    return result;
}
string getFractionString(long long numerator, long long denominator){
    long long remainder = numerator;
    string result;
    map<int, int> mp; // remainder to index map
    int repeatationStartIndex = -1;
    while(remainder){
        if(mp.find(remainder) != mp.end()){
            repeatationStartIndex = mp[remainder];
            break;
        }else{
            mp[remainder] = result.size(); // index
        }
        remainder *= 10;
        result.push_back(remainder/denominator + '0');
        remainder = remainder%denominator;
    }
    if(repeatationStartIndex != -1){
        result += ")";
        result = insertOpenBraceBeforeN(repeatationStartIndex, result);
    }
    return result;
}
//string Solution::fractionToDecimal(int nn, int dd) {
string fractionToDecimal(int nn, int dd) {
    long long numerator = nn, denominator = dd;
    bool isNegative = false;
    if(numerator < 0){
        numerator = -1 * numerator;
        isNegative = true;
    }
    if(denominator < 0){
        denominator = -1*denominator;
        isNegative = !isNegative;
    }
    string part1 = toString(numerator/denominator);
    if(numerator%denominator == 0){
        return part1;
    }
    numerator = numerator%denominator;
    string part2 = getFractionString(numerator, denominator);
    string sign = isNegative ? "-" : "";
    return sign + part1 + string(1, '.') + part2;
}
int main()
{
    cout << fractionToDecimal(-1, -2147483648) << endl;
    return 0;
    cout << fractionToDecimal(-2147483648,-1) << endl;
    cout << fractionToDecimal(1,2) << endl;
    cout << fractionToDecimal(2,1) << endl;
    cout << fractionToDecimal(2,3) << endl;
    cout << fractionToDecimal(1,11) << endl;
    cout << fractionToDecimal(-1,11) << endl;
    cout << fractionToDecimal(1,-11) << endl;
    cout << fractionToDecimal(-1,-11) << endl;
    cout << fractionToDecimal(-1,-1) << endl;
    return 0;
}
