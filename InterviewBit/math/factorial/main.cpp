#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int Solution::trailingZeroes(int num) {
    int result = 0;
    int divisor = 5;
    while(divisor <= num && divisor > 0){
        result += num/divisor;
        divisor *= 5;
    }
    return result;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
