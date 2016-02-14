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

//vector<int> Solution::maxone(vector<int> &arr, int maxFlips) {
vector<int> maxone(vector<int> &arr, int maxFlips) {
    int len = arr.size();

    vector<vector<int> > nOnes(len, vector<int>(len, 0));

    for(int i=0; i<len; i++){
        nOnes[i][i] += arr[i];
    }
    int maxLen = 0, maxSi, maxEi;
    for(int size=2; size<=len; size++){
        for(int si=0; si + size <= len; si++){
            int ei = size+si-1;
            nOnes[si][ei] = nOnes[si][si] + nOnes[si+1][ei];

            if(

               size <= maxFlips + nOnes[si][ei] // if this substring is valid
               && size > maxLen){ // if size of this substring is greater than one encountered so far.
                maxLen = size;
                maxSi = si;
                maxEi = ei;
            }
        }
    }

    vector<int> result;
    for(int index=maxSi; index<=maxEi; index++){
        result.push_back(index);
    }
    return result;
}

//vector<int> Solution::maxone(vector<int> &arr, int maxFlips) {
vector<int> maxone2(vector<int> &arr, int maxFlips) {
    int len = arr.size();
    int i=0, j=0, nZeros = (arr[0]==0 ? 1 : 0);
    int maxLen = 0, maxSi, maxEi;
    while(j<len){
        if(nZeros < maxFlips){
            if(j+1 < len){
                j++;
            }else{
                break;
            }
            if(arr[j] == 0){
                nZeros++;
            }
        }else if(nZeros == maxFlips && j+1<len && arr[j+1] == 1){
            j++;
        }else{
            if(i == len-1){
                break;
            }
            if(arr[i] == 0){
                nZeros--;
            }
            i++;
        }
        int curLen = j-i+1;
        if(curLen > maxLen){
            maxLen = curLen;
            maxSi = i;
            maxEi = j;
        }
    }

    vector<int> result;
    for(int index=maxSi; index<=maxEi; index++){
        result.push_back(index);
    }
    return result;
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(0);
    vector<int> result = maxone2(arr, 2);
    for(int index=0; index<result.size(); index++){
        cout << result[index] << endl;
    }
    return 0;
}
