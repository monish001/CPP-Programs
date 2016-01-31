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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
    void Print(){
        cout<<start<<" "<<end<<endl;
    }
};
bool comparator(Interval a, Interval b){
    return a.start<b.start;
}
vector<Interval> merge(vector<Interval> &A) {
    vector<Interval> result;

    sort(A.begin(), A.end(), comparator);

    int len = A.size(), indexResult = 0;
    result.push_back(A[0]);

    for(int indexA=1; indexA<len; indexA++){
        if(result[indexResult].end >= A[indexA].start){
            result[indexResult].end = max(result[indexResult].end, A[indexA].end);
        }else{
            result.push_back(A[indexA]);
            indexResult++;
        }
    }

    return result;
}

int main()
{
    vector<Interval> intervals;
    intervals.push_back(Interval(1,3));
    intervals.push_back(Interval(2,6));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(15,18));

    vector<Interval> intervals1;
    intervals1.push_back(Interval(1,3));

    vector<Interval> result = merge(intervals1);
    for(int i=0; i<result.size(); i++){
        result[i].Print();
        //cout<<result[i]<<"\t";
    }

    return 0;
}
