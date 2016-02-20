#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
bool comparePeople(const pair<int, int>& p1, const pair<int, int>& p2){
    return p1.first < p2.first;
}
void _insert(const int pNo, int inFronts, vector<int>& arr){
    for(int i=0; i<arr.size(); i++){
        if(inFronts == 0 && arr[i] == INT_MAX){
            arr[i] = pNo;
            return;
        }
        if(arr[i] == INT_MAX){
            inFronts--;
        }
    }
}
//vector<int> Solution::order(vector<int> &heights, vector<int> &infronts) {
vector<int> order(vector<int> &heights, vector<int> &infronts) {
    vector<pair<int, int> > heightToInFronts;
    int nPeople = heights.size();
    vector<int> result(nPeople, INT_MAX);
    for(int p=0; p<nPeople; p++){
        heightToInFronts.push_back(make_pair(heights[p], infronts[p]));
    }
    sort(heightToInFronts.begin(), heightToInFronts.end(), comparePeople);
    for(int p=0; p<nPeople; p++){
        int curInFronts = heightToInFronts[p].second, personNo = heightToInFronts[p].first;
        _insert(personNo, curInFronts, result);
    }
    return result;
}
void printVec(const vector<int>& vec){
    int len = vec.size();
    for(int index=0; index<len; index++){
        cout<<"\t"<<vec[index];
    }
    cout<<endl;
}
int main()
{
    vector<int> hts;
    hts.push_back(5);
    hts.push_back(3);
    hts.push_back(2);
    hts.push_back(6);
    hts.push_back(1);
    hts.push_back(4);
    vector<int> inf;
    inf.push_back(0);
    inf.push_back(1);
    inf.push_back(2);
    inf.push_back(0);
    inf.push_back(3);
    inf.push_back(2);
    printVec(order(hts, inf));
    return 0;
}
