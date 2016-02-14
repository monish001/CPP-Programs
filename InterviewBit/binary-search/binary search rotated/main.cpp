#include<iostream>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include <climits>
#include <cmath>
using namespace std;

#define ll long long
#define pii pair<int,int>
int binarySearch(const vector<int> &arr, const int sIndex, const int eIndex, const int searchItem){
    if(eIndex<sIndex){
        return -1;
    }
    int mIndex = (sIndex + eIndex)/2;
    if(searchItem == arr[mIndex]){
        return mIndex;
    }else if(searchItem < arr[sIndex] && arr[sIndex] < arr[mIndex]){
        return binarySearch(arr, mIndex+1, eIndex, searchItem);
    }else if(arr[sIndex] <= searchItem && searchItem < arr[mIndex]){
        return binarySearch(arr, sIndex, mIndex-1, searchItem);
    }else if(arr[sIndex] <= arr[mIndex]){
        return binarySearch(arr, mIndex+1, eIndex, searchItem);
    }else if(arr[mIndex] < searchItem && searchItem <= arr[eIndex]){
        return binarySearch(arr, mIndex+1, eIndex, searchItem);
    }else{
        return binarySearch(arr, sIndex, mIndex-1, searchItem);
    }
}
int search(const vector<int> &A, int B){
    return binarySearch(A, 0, A.size()-1, B);
}
int main()
{
    int x1[] = {4,5,6,7,0,1,2};
    vector<int> vec1(x1, x1 + sizeof x1 / sizeof x1[0]);
    cout << search(vec1, 3) << endl; // -1
    cout << search(vec1, 4) << endl; // 0
    cout << search(vec1, 7) << endl; // 3
    cout << search(vec1, 0) << endl; // 4
    cout << search(vec1, 2) << endl; // 6
    return 0;
}
