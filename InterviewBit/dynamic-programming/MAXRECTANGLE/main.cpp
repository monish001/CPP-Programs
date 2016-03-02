#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
bool isFull(const int result, const int sr, const int er, const int sc, const int ec){
    if(er-sr < 0 || ec-sc < 0){
        return true;
    }
    return result == (er-sr+1)*(ec-sc+1);
}
int _maximalRectangle3(const vector<vector<int> > &mat, const int nRows, const int nCols){
    vector<string> isAllOnes(nRows, string(nCols, 0));
    return 1;
}
int _maximalRectangle2(const vector<vector<int> > &mat, const int nRows, const int nCols) {
    //int result[nRows][nRows][nCols][nCols] = {0};
//cout<<"nRows:"<<nRows<<", nCols:"<<nCols<<endl;
    vector<vector<vector<string> > > result(nRows, vector<vector<string > >(nRows, vector<string >(nCols, string(nCols, 0))));
    int maxResult = 0;
    for(int rowSize=1; rowSize<=nRows; rowSize++){
        for(int colSize=1; colSize<=nCols; colSize++){
            for(int sr=0; sr<=nRows-rowSize; sr++){
                int er = sr+rowSize-1;
                for(int sc=0; sc<=nCols-colSize; sc++){
                    int ec = sc+colSize-1, innerResult;
                    if(ec==sc && er==sr){
                        innerResult = mat[sr][sc];
                    }else{
                        int op1 = er-sr > 0 ? result[sr][er-1][sc][ec] : 0;
                        int op2 = ec-sc > 0 ? result[sr][er][sc][ec-1] : 0;

                        // if all elems are 1s
                        if(isFull(op1, sr, er-1, sc, ec) && isFull(op2, sr, er, sc, ec-1) && mat[er][ec] == 1){
                            innerResult = rowSize*colSize;
                        }else{
                            if(op1 == colSize*(rowSize-1)){
                                //op1 += mat[er][ec];
                            }
                            if(op2 == (colSize-1)*rowSize){
                                //op2 += mat[er][ec];
                            }
                            innerResult = max(max(op1, op2), mat[er][ec]);
                        }
                    }
cout<<sr<<" "<<er<<" "<<sc<<" "<<ec<<" "<<innerResult<<endl;
                    result[sr][er][sc][ec] = innerResult;
                    maxResult = max(innerResult, maxResult);
                }
            }
        }
    }
    return maxResult;// result[0][nRows-1][0][nCols-1];
}
int _maximalRectangle(const vector<vector<int> > &mat,
                       const int sr, const int er, const int sc, const int ec,
                       map< pair< pair<int, int>, pair<int, int> >, int> &memo) {
    pair< pair<int, int>, pair<int, int> > inputKey = make_pair(make_pair(sr, er), make_pair(sc, ec));
    if(memo.find(inputKey) == memo.end()){
        int nRows = er-sr+1, nCols = ec-sc+1, result;
        if(nRows<1 || nCols<1){
            result = 0;
        }else if(nRows == 1 && nCols==1){
            result = mat[sr][sc];
        }else{
            int op1 = _maximalRectangle(mat, sr, er-1, sc, ec, memo);
            int op2 = _maximalRectangle(mat, sr, er, sc, ec-1, memo);
            if(op2 == nRows*(nCols-1) && op1 == nCols*(nRows-1) && mat[er][ec] == 1){
                result = nRows*nCols;
            }else{
                result = max(op1, op2);
            }
        }
        memo[inputKey] = result;
cout<<sr<<" "<<er<<" "<<sc<<" "<<ec<<" "<<result<<endl;
    }
    return memo[inputKey];
}
//int Solution::maximalRectangle(vector<vector<int> > &mat) {
int maximalRectangle(vector<vector<int> > &mat) {
    int nRows = mat.size();
    if(nRows == 0){
        return 0;
    }
    int nCols = mat[0].size();
    return _maximalRectangle2(mat, nRows, nCols);

    // row start and end. Then col start and end indices.
    map< pair< pair<int, int>, pair<int, int> >, int> memo;
    return _maximalRectangle(mat, 0, nRows-1, 0, nCols-1, memo);
}
int main()
{
    vector<vector<int> > mat;
    vector<int> r1;
    r1.push_back(1);
    r1.push_back(1);
    r1.push_back(1);
    r1.push_back(1);
    r1.push_back(1);
    r1.push_back(1);
    r1.push_back(0);
    r1.push_back(1);
    r1.push_back(1);
    r1.push_back(1);
    r1.push_back(1);
    r1.push_back(1);
    r1.push_back(1);
    r1.push_back(1);
    r1.push_back(1);
    vector<int> r2;
    r2.push_back(1);
    r2.push_back(0);
    r2.push_back(1);
    r2.push_back(1);
    r2.push_back(0);
    r2.push_back(1);
    r2.push_back(1);
    r2.push_back(1);
    r2.push_back(1);
    r2.push_back(1);
    r2.push_back(1);
    r2.push_back(1);
    r2.push_back(1);
    r2.push_back(1);
    r2.push_back(1);
    r2.push_back(1);
    vector<int> r3;
    r3.push_back(1);
    r3.push_back(1);
    r3.push_back(1);
    r3.push_back(1);
    r3.push_back(1);
    r3.push_back(1);
    r3.push_back(1);
    r3.push_back(1);
    r3.push_back(1);
    r3.push_back(1);
    r3.push_back(1);
    r3.push_back(1);
    r3.push_back(1);
    r3.push_back(1);
    r3.push_back(1);
    r3.push_back(1);
    mat.push_back(r1);
    mat.push_back(r2);
    mat.push_back(r3);
    cout << maximalRectangle(mat) << endl;
    return 0;
}
