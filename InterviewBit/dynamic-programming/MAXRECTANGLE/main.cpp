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
vector<vector<int> > getNumOnesInRowAtEachLocation(const vector<vector<int> > &mat, const int nRows, const int nCols){
    vector<vector<int> > max_x(nRows, vector<int>(nCols, 0));
    for(int ri=0; ri<nRows; ri++){
        if(nCols > 0){
            max_x[ri][nCols-1] = mat[ri][nCols-1];
        }
        for(int ci=nCols-2; ci>=0; ci--){
            max_x[ri][ci] = mat[ri][ci] == 1 ? max_x[ri][ci+1] + 1 : 0;
        }
    }
    return max_x;
}
void printVecVec(const vector<vector<int> > vecVec, const vector<vector<int> > vecVec2){
    cout<<"Format: ri,ci:inputMatrix:nOnes"<<endl;
    for(int index=0; index<vecVec.size(); index++){
        for(int innerIndex=0; innerIndex<vecVec[index].size(); innerIndex++){
            cout<<index<<","<<innerIndex<<":"<<vecVec[index][innerIndex]<<":"<<vecVec2[index][innerIndex]<<"\t";
        }
        cout<<endl;
    }
}
int _maximalRectangle3(const vector<vector<int> > &mat, const int nRows, const int nCols){
    vector<vector<int> > max_x = getNumOnesInRowAtEachLocation(mat, nRows, nCols);
//printVecVec(mat, max_x);
    int result = 0;
    for(int ci=0; ci<nCols; ci++){
        for(int ri=0; ri<nRows; ri++){
            int numOnes, curMaxArea;
            if(nRows > 0){
                curMaxArea = numOnes = max_x[ri][ci];
            }

            for(int iRi = ri+1; iRi<nRows; iRi++){
                numOnes = min(numOnes, max_x[iRi][ci]);
                curMaxArea = max(curMaxArea, numOnes * (iRi-ri+1));
            }
//cout<<"Area at "<<ri<<","<<ci<<":"<<curMaxArea<<endl;
            result = max(result, curMaxArea);
        }
    }
    return result;
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
    return _maximalRectangle3(mat, nRows, nCols);
    return _maximalRectangle2(mat, nRows, nCols);

    // row start and end. Then col start and end indices.
    map< pair< pair<int, int>, pair<int, int> >, int> memo;
    return _maximalRectangle(mat, 0, nRows-1, 0, nCols-1, memo);
}
int main()
{
    vector<vector<int> > mat;
    int arr1[] = {0, 0, 1, 0, 0, 0, 1, 0, 1};
    vector<int> r1(arr1, arr1+sizeof(arr1)/sizeof(arr1[0]));
    mat.push_back(r1);
    int arr2[] = {0, 1, 1, 0, 0, 0, 0, 0, 0};
    vector<int> r2(arr2, arr2+sizeof(arr2)/sizeof(arr2[0]));
    mat.push_back(r2);
    int arr3[] = {0, 0, 1, 0, 1, 0, 1, 0, 1};
    vector<int> r3(arr3, arr3+sizeof(arr3)/sizeof(arr3[0]));
    mat.push_back(r3);
    int arr4[] = {0, 1, 0, 0, 0, 1, 1, 0, 1};
    vector<int> r4(arr4, arr4+sizeof(arr4)/sizeof(arr4[0]));
    mat.push_back(r4);
    int arr5[] = {0, 1, 0, 0, 0, 0, 1, 1, 1};
    vector<int> r5(arr5, arr5+sizeof(arr5)/sizeof(arr5[0]));
    mat.push_back(r5);
    int arr6[] = {1, 0, 1, 1, 1, 0, 1, 1, 1};
    vector<int> r6(arr6, arr6+sizeof(arr6)/sizeof(arr6[0]));
    mat.push_back(r6);
    int arr7[] = {1, 1, 1, 1, 0, 1, 1, 1, 1};
    vector<int> r7(arr7, arr7+sizeof(arr7)/sizeof(arr7[0]));
    mat.push_back(r7);
    int arr8[] = {1, 1, 1, 0, 1, 0, 1, 0, 1};
    vector<int> r8(arr8, arr8+sizeof(arr8)/sizeof(arr8[0]));
    mat.push_back(r8);
    cout << maximalRectangle(mat) << endl;
    return 0;
}
