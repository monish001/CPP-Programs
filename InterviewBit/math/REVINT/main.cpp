#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int reverse(int A) {
    long long num = abs(A);
    long long result = 0;
    while(num){
        result = result*10 + num%10;
        num/=10;
    }
    if(result > INT_MAX || result < INT_MIN){
        result = 0;
    }
    if(A<0){
        result = -1*result;
    }
    return (int)result;
}
int main()
{
    cout << reverse(123) << endl;
    cout << reverse(-1146467285) << endl;
    cout << INT_MAX<<":"<<reverse(INT_MAX) << endl;
    return 0;
}
