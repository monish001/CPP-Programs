#include <iostream>
#include <map>
#include <vector>
using namespace std;

//int _adjacent(const vector<vector<int> > &mat, const int sColIndex, const int eColIndex, vector<vector<int> >& memo) {
int _adjacent(const vector<vector<int> > &mat, const int sColIndex, const int eColIndex, map<pair<int, int>, int>& memo) {
    pair<int, int> mpKey = make_pair(sColIndex, eColIndex);
    if(memo.find(mpKey) != memo.end()){
        return memo[mpKey];
    }
    int maxColIndex = mat[0].size()-1;
    if(sColIndex > eColIndex || eColIndex > maxColIndex){
        return 0;
    }
    int nCols = eColIndex-sColIndex+1;
    if(nCols == 1){
        memo[mpKey] = max(0, max(mat[0][sColIndex], mat[1][sColIndex]));
    }else if(nCols == 2){
        int col1 = _adjacent(mat, sColIndex, sColIndex, memo);
        int col2 = _adjacent(mat, eColIndex, eColIndex, memo);
        memo[mpKey] = max(0, max(col1, col2));
    }else if(nCols == 3){
        int col1 = _adjacent(mat, sColIndex, sColIndex, memo);
        int col2 = _adjacent(mat, sColIndex+1, sColIndex+1, memo);
        int col3 = _adjacent(mat, sColIndex+2, sColIndex+2, memo);
        memo[mpKey] = max(0, max(col1, max(col2, max(col3, (col1+col3)))));
    }else{
        int op1 = 0,
            op2 = _adjacent(mat, sColIndex+2, eColIndex, memo),
            op3 = _adjacent(mat, sColIndex+3, eColIndex, memo);
        int op4 = _adjacent(mat, sColIndex, sColIndex, memo) + op2,
            op5 = _adjacent(mat, sColIndex+1, sColIndex+1, memo) + op3;
        memo[mpKey] = max(op1, max(op2, max(op3, max(op4, (op5)))));
    }
    return memo[mpKey];
}
//int Solution::adjacent(vector<vector<int> > &mat) {
int adjacent(vector<vector<int> > &mat) {
    int nCols = mat[0].size();
    //vector<vector<int> > memo(nCols, vector<int>(nCols, INT_MAX));
    map<pair<int, int>, int> memo;
    return _adjacent(mat, 0, nCols-1, memo);
}
int main()
{
    vector<vector<int> > mat;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    vector<int> v2;
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(5);
    mat.push_back(v1);
    mat.push_back(v2);
    cout << adjacent(mat) << endl;
    return 0;
}
