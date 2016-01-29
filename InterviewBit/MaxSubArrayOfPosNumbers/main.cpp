/*
QUESTION

Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]

NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index
*/
#include<iostream>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include <climits>
using namespace std;

#define ll long long
#define pii pair<int,int>

vector<int> maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ll maxSum = 0,
        resultStartIndex = INT_MAX,
        resultEndIndex = INT_MAX,
        len = A.size();
    for(int size = 1; size <= len; size++){
        for(int startIndex = 0; startIndex<len; startIndex++){
            int endIndex = startIndex + size - 1;
            if(endIndex >= len){
                break;
            }
            ll curSum = 0;
            bool skip = false;
            for(int index = startIndex; index<=endIndex; index++){
                if(A[index]<0){
                    skip = true;
                    break;
                }
                curSum += A[index];
            }
            if(skip==true){
            }else if(
                (maxSum < curSum) ||
                (maxSum == curSum && endIndex-startIndex > resultEndIndex-resultStartIndex) ||
                (maxSum == curSum && endIndex-startIndex == resultEndIndex-resultStartIndex && startIndex < resultStartIndex)
            ){
                maxSum = curSum;
                resultStartIndex = startIndex;
                resultEndIndex = endIndex;
            }
        }
    }

    vector<int> result;
    if(resultStartIndex!=INT_MAX && resultEndIndex!=INT_MAX){
        for(int index = resultStartIndex; index<=resultEndIndex; index++){
            result.push_back(A[index]);
        }
    }
    return result;
}

vector<int> maxset2(const vector<int> &A) {
    int maxSi = INT_MAX, maxEi = INT_MAX;
    long long maxSum = INT_MIN;
    vector<int> result;
    int curSi=INT_MAX, curEi=INT_MAX;
    long long curSum = INT_MIN;
    int len = A.size();

    for(int index = 0; index<len; index++){
        if(A[index] >= 0){
            if(curSum == INT_MIN){
                curSi = index;
                curSum = 0;
            }
            curEi = index;
            curSum += A[index];
            if(
                (maxSum < curSum) ||
                (maxSum == curSum && curEi-curSi > maxEi-maxSi) ||
                (maxSum == curSum && curEi-curSi== maxEi-maxSi && curSi < maxSi)
            ){
                maxSum = curSum;
                maxSi = curSi;
                maxEi = curEi;
            }
        }else{
            // reset curSum
            curSum = INT_MIN;
        }
    }

    if(maxSum == INT_MIN){
        return result;
    }
    for(int index=maxSi; index<=maxEi; index++){
        result.push_back(A[index]);
    }
    return result;
}

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(-1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(1);

    vector<int> vec1;
    vec1.push_back(0);
    vec1.push_back(0);
    vec1.push_back(-1);
    vec1.push_back(0);

    vector<int> vec2;
    vec2.push_back(-1);
    vec2.push_back(-1);
    vec2.push_back(-1);

    vector<int> vec3;
    vec3.push_back(1);
    vec3.push_back(2);
    vec3.push_back(-1);
    vec3.push_back(2);
    vec3.push_back(1);

    vector<int> result = maxset2(vec3);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<"\t";
    }
    return 0;
}
