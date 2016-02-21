// you can use includes, for example:
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
using namespace std;
long long summation(int num){
    long long _num = num;
    return _num * (_num+1) /2;
}
int solution(vector<int> &A) {
    map<int, int> freqCount;
    int nNums = A.size();
    for(int i=0; i<nNums; i++){
        int num = A[i];
        if(freqCount.find(num) == freqCount.end()){
            freqCount[num] = 0;
        }
        freqCount[num]++;
    }
    typedef map<int, int>::iterator it_type;
    long long result = 0;
    for(it_type iterator = freqCount.begin(); iterator != freqCount.end(); iterator++) {
        //int num = iterator->first;
        int freq = iterator->second;
        result += summation(freq-1);
        if(result >= 1000000000){
            result = 1000000000;
            break;
        }
    }
    return (int)(result);
}
int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    cout << solution(v1) << endl;
    return 0;
}
