#include <iostream>
#include <vector>
using namespace std;
void resetRow(vector<string>& chessBoard, const int rowIndex, const char resetValue, const int nQueens){
    chessBoard[rowIndex] = string(nQueens, resetValue);
}
bool anyVerticalQueen(const vector<string>& chessBoard, const int inputRowIndex, const int inputColIndex){
    for(int rowIndex=0; rowIndex<inputRowIndex; rowIndex++){
        if(chessBoard[rowIndex][inputColIndex] == 'Q'){
            return true;
        }
    }
    return false;
}
bool anyLeftDiagonalQueen(const vector<string>& chessBoard, const int inputRowIndex, const int inputColIndex){
    int rowIndex = inputRowIndex-1, colIndex = inputColIndex-1;
    while(rowIndex >= 0 && colIndex >= 0){
        if(chessBoard[rowIndex--][colIndex--] == 'Q'){
            return true;
        }
    }
    return false;
}
bool anyRightDiagonalQueen(const vector<string>& chessBoard, const int inputRowIndex, const int inputColIndex, const int nQueens){
    int rowIndex = inputRowIndex-1, colIndex = inputColIndex+1;
    while(rowIndex >= 0 && colIndex < nQueens){
        if(chessBoard[rowIndex--][colIndex++] == 'Q'){
            return true;
        }
    }
    return false;
}
bool isValidMove(const vector<string>& chessBoard, const int rowIndex, const int colIndex, const int nQueens){
    bool isInvalid = anyVerticalQueen(chessBoard, rowIndex, colIndex)
        || anyLeftDiagonalQueen(chessBoard, rowIndex, colIndex)
        || anyRightDiagonalQueen(chessBoard, rowIndex, colIndex, nQueens);
    return !isInvalid;
}
vector<vector<string> > result;
void printChessboard(const vector<string>& arr){
    int nCols = arr.size();
    for(int colIndex=0; colIndex<nCols; colIndex++){
        cout<<arr[colIndex]<<endl;
    }
    cout<<endl;
}
void printChessboards(const vector<vector<string> >& arr){
    int nRows = arr.size(), nCols = arr[0].size();
    for(int rowIndex = 0; rowIndex<nRows; rowIndex++){
        cout<<"Solution "<<rowIndex+1<<":"<<endl;
        printChessboard(arr[rowIndex]);
    }
}
void _solveNQueens(vector<string>& chessBoard, const int nQueens, const int rowIndex){
    if(rowIndex==nQueens){
        //printChessboard(chessBoard);
        result.push_back(vector<string>(chessBoard));
        return;
    }
    // Try to place queen one by one in each column after checking whether that's a valid move or not.
    for(int colIndex=0; colIndex<nQueens; colIndex++){
        resetRow(chessBoard, rowIndex, '.', nQueens);
        if(isValidMove(chessBoard, rowIndex, colIndex, nQueens)){
            chessBoard[rowIndex][colIndex] = 'Q';
            _solveNQueens(chessBoard, nQueens, rowIndex+1);
        }
    }
};
//vector<vector<string> > Solution::solveNQueens(int nQueens) {
vector<vector<string> > solveNQueens(int nQueens) {
    vector<string> chessBoard(nQueens, string(nQueens, '.'));
    _solveNQueens(chessBoard, nQueens, 0);
    return result;
}
int main()
{
    solveNQueens(1);
    printChessboards(result);
    return 1;
}
