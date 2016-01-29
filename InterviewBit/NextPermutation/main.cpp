/*
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.

If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

The replacement must be in-place, do not allocate extra memory.

Examples:

1,2,3 → 1,3,2

3,2,1 → 1,2,3

1,1,5 → 1,5,1

20, 50, 113 → 20, 113, 50
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

void swapVectorElem(vector<int> &A, const int index1, const int index2){
    int tmp = A[index1];
    A[index1] = A[index2];
    A[index2] = tmp;
}
void reverseVector(vector<int> &A){
    int len = A.size();
    for(int index = 0; index<len/2; index++){
        swapVectorElem(A, index, len-1-index);
    }
}
void sortVectorTillEnd(vector<int>& A, int si){
    sort(A.begin() + si, A.end());
}
void fixPerm(vector<int> &A, const int indexDigitToMoveRight){
    int indexDigitToMoveLeft = INT_MIN,
        len = A.size();
    for(int index = indexDigitToMoveRight+1; index<len; index++){
        if(A[index] > A[indexDigitToMoveRight]){
            if(indexDigitToMoveLeft == INT_MIN || A[indexDigitToMoveLeft]>A[index]){
                indexDigitToMoveLeft = index;
            }
        }
    }
    swapVectorElem(A, indexDigitToMoveRight, indexDigitToMoveLeft);
    sortVectorTillEnd(A, indexDigitToMoveRight+1);
}
void nextPermutation(vector<int> &A) {
    bool isSolved = false;
    int len = A.size();
    for(int index = len-2; index>=0; index--){
        if(A[index]<A[index+1]){
            fixPerm(A, index);
            isSolved = true;
            break;
        }
    }
    if(isSolved == false){
        reverseVector(A);
    }
}

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    vector<int> vec1;
    vec1.push_back(3);
    vec1.push_back(2);
    vec1.push_back(1);

    vector<int> vec2;
    vec2.push_back(1);
    vec2.push_back(1);
    vec2.push_back(5);

    vector<int> vec3;
    vec3.push_back(20);
    vec3.push_back(50);
    vec3.push_back(113);

    vector<int> vec4;
    vec4.push_back(1);
    vec4.push_back(3);
    vec4.push_back(2);

    vector<int> vec5;
    vec5.push_back(2);
    vec5.push_back(3);
    vec5.push_back(1);

    //for(int i=0; i<vec.size(); i++){
        //cout<<vec[i]<<"\t";
    //}
    cout<<endl;
    nextPermutation(vec);
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<"\t";
    }
    return 0;
}
