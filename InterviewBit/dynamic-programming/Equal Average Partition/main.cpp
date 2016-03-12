#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
void printVecVec(vector<vector<int> > vecVec){
    cout<<"In printVecVec:\n";
    for(unsigned int index=0; index<vecVec.size(); index++){
        for(unsigned int innerIndex=0; innerIndex<vecVec[index].size(); innerIndex++){
            cout<<vecVec[index][innerIndex]<<"\t";
        }
        cout<<endl;
    }
}
bool hasFraction(double num){
    return (double)(int)(num) != num;
}
bool sortLists(const vector<int>& list1, const vector<int>& list2){
    if(list1.size() < list2.size()){
        return true;
    }else if(list1.size() > list2.size()){
        return false;
    }
    vector<int> l1(list1.begin(), list1.end()), l2(list2.begin(), list2.end());
    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());
    int i1=0, i2=0, sz1=l1.size(), sz2=l2.size();
    while(i1<sz1 && i2<sz2 && l1[i1] == l2[i2]){
        i1++; i2++;
    }
    return l1[i1]<l2[i2];
}
long long toLongLong(int num){
    return num;
}
vector<vector<int> > findNElemsWithSumS(const vector<int>& input, const int si, const int count, const int sum, map<long long, vector<vector<int> > >& memo){
    long long key = (toLongLong(si)<<40) + (toLongLong(count)<<20) + sum;
    if(memo.find(key)==memo.end()){
        vector<vector<int> > result;
        int nElems = input.size();
        if(count == 0 || sum<0){
            ;
        }else if(count == 1){
            for(int i=si; i<nElems; i++){
                int curElem = input[i];
                if(sum == curElem){
                    vector<int> list; list.push_back(curElem);
                    result.push_back(list);
                }
            }
        }else{
            for(int i=si; i<nElems; i++){
                int curElem = input[i];
                vector<vector<int> > lists = findNElemsWithSumS(input, i+1, count-1, sum-curElem, memo);
                for(unsigned int i=0; i<lists.size(); i++){
                    vector<int> list = lists[i];
                    list.push_back(curElem);
                    result.push_back(list);
                    break;
                }
            }
        }
//cout<<"For startIndex:"<<si<<", count:"<<count<<", sum:"<<sum<<":"<<endl;
//printVecVec(result);
        memo[key] = result;
    }
    return memo[key];

}
//vector<vector<int> > Solution::avgset(vector<int> &input) {
vector<vector<int> > avgset(vector<int> &input) {
    vector<vector<int> > result;
    sort(input.begin(), input.end());
    int nElems = input.size(), sumN = 0;
    for(int i=0; i<nElems; i++){
        sumN += input[i];
    }
    vector<int> group1;
    map<long long, vector<vector<int> > > memo;
    for(int sz=1; sz<nElems; sz++){
        double reqdSum = sumN * sz * 1.0 / nElems;
        if(hasFraction(reqdSum)){
            continue;
        }
        vector<vector<int> > allSols = findNElemsWithSumS(input, 0, sz, reqdSum, memo);
        sort(allSols.begin(), allSols.end(), sortLists);
        if(!allSols.empty()){
            group1 = allSols[0];
            break;
        }
    }
    vector<int> group2;
    sort(input.begin(), input.end());
    sort(group1.begin(), group1.end());
    int grp1Index = 0, nGrp1Elems = group1.size();
    if(group1.empty()){
        return result;
    }
    for(int i=0; i<nElems; i++){
        int curElem = input[i];
        if(grp1Index < nGrp1Elems && group1[grp1Index] == curElem){
            grp1Index++;
        }else{
cout<<"pushing "<<curElem<<" in grp2\n";
            group2.push_back(curElem);
        }
    }
    result.push_back(group1);
    result.push_back(group2);
    return result;
}
int main()
{
    int arr8[] = {1,7,15,29,11,9};
    vector<int> r8(arr8, arr8+sizeof(arr8)/sizeof(arr8[0]));
    vector<vector<int> > result8 = avgset(r8);
    printVecVec(result8);
    cout<<endl;

    int arr1[] = {18, 29, 0, 47, 0, 41, 40, 28, 7, 1};
    vector<int> r1(arr1, arr1+sizeof(arr1)/sizeof(arr1[0]));
    vector<vector<int> > result1 = avgset(r1);
    printVecVec(result1);

    int arr2[] = {28, 10, 2, 44, 33, 31, 39, 46, 1, 24, 32, 31, 28, 9, 13, 40, 46, 1, 16, 18, 39, 13, 48, 5};
    vector<int> r2(arr2, arr2+sizeof(arr2)/sizeof(arr2[0]));
    vector<vector<int> > result2 = avgset(r2);
    printVecVec(result2);

    int arr3[] = {41, 7, 33, 10, 9, 27, 8, 16, 23, 26};
    vector<int> r3(arr3, arr3+sizeof(arr3)/sizeof(arr3[0]));
    vector<vector<int> > result3 = avgset(r3);
    printVecVec(result3);

    return 0;
}
