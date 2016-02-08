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

vector<int> intersect(const vector<int> &arr1, const vector<int> &arr2) {
//vector<int> Solution::intersect(const vector<int> &arr1, const vector<int> &arr2) {
    int index1 = 0, index2 = 0;
    int len1 = arr1.size(), len2 = arr2.size();
    vector<int> result;
    while(index1 < len1 && index2 < len2){
        if(arr1[index1] < arr2[index2]){
            index1++;
        }else if(arr1[index1] > arr2[index2]){
            index2++;
        }else{
            result.push_back(arr1[index1]);
            index1++;
            index2++;
        }
    }
    return result;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
