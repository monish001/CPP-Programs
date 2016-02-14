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
//int Solution::numSetBits(unsigned int num) {
int numSetBits(unsigned int num) {
    int count=0;
    while(num){
        if(num%2 != 0){
            count++;
        }
        num >>= 1;
    }
    return count;
}

int main()
{
    cout << numSetBits(11) << endl;
    return 0;
}
