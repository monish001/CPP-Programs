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

vector<int> wave(vector<int> &A) {
    vector<int> result = A;
    sort(result.begin(), result.end());
    int len = A.size();
    for(int index = 0; index+1<len; index = index+2){
        //cout<<"Swapping index " << index << " and " << index+1<<endl;
        swapVectorElem(result, index, index+1);
    }

    return result;
}


int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    vector<int> vec1;
    vec1.push_back(4);

    vector<int> vec2;
    vec2.push_back(4);
    vec2.push_back(3);
    vec2.push_back(2);
    vec2.push_back(1);

    vector<int> vec3;
    vec3.push_back(1);
    vec3.push_back(2);
    vec3.push_back(3);

    vector<int> result = wave(vec);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<"\t";
    }
    return 0;
}
