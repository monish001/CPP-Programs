#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
int getNumDigits(int number){
    int count = 0;
    while(number){
        count++;
        number/=10;
    }
    return count;
}
int getDigitAt(int number, int index){
    int result = number%10;
    number/=10;
    while(index--){
        result = number%10;
        number/=10;
    }
    return result;
}
string intToString(int number){
    string result;
    int len = getNumDigits(number);
    for(int index=0; index<len; index++){
        char newDigitAsChar = number%10 + '0';
        result = string(1, newDigitAsChar) + result;
        number/=10;
    }
    return result;
}
int colorful(int inputNum) {
//int Solution::colorful(int inputNum) {
    map<int, bool> productTracking;
    int nDigits = getNumDigits(inputNum);
    string inputNumStr = intToString(inputNum);
    vector<vector<int> > product(nDigits, vector<int>(nDigits, 1));

    for(int index=0; index<nDigits; index++){
        int curProduct = inputNumStr[index] - '0';
        product[index][index] = curProduct;
        if(productTracking.find(curProduct) != productTracking.end()){
            return 0;
        }
        productTracking[curProduct] = true;
    }
    for(int size = 2; size<=nDigits; size++){
        for(int si=0; si<=nDigits-size; si++){
            int ei = si + size -1;
            int curProduct = product[si][si] * product[si+1][ei];
            if(productTracking.find(curProduct) != productTracking.end()){
                return 0;
            }
            productTracking[curProduct] = true;
            product[si][ei] = curProduct;
        }
    }
    return 1;
}

int main()
{
    cout << colorful(234) << endl;
    cout << colorful(57) << endl;
    cout << colorful(1) << endl;
    cout << colorful(2) << endl;
    cout << colorful(5) << endl;
    cout << colorful(11) << endl;
    cout << colorful(12) << endl;
    cout << colorful(9999) << endl;
    cout << colorful(236) << endl;
    return 0;
}
