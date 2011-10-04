//INCOMPLETE YET
//This is 8-queen problem program.
/*
void printSolution(string &rows){
    for each i 0 to 7
        for each j 7 to 0
            print rows[i] & 1<<7
        print newline
}
*/
#define NumOfQueens 8
#include <iostream>
using namespace std;

int colForRow[NumOfQueens];
void printSolution(){
	for(int i=0; i<NumOfQueens; i++){//    for each i 0 to 7
		for(int j=0; j<NumOfQueens; j++)//        for each j 7 to 0
			(colForRow[i]==j)?(cout<<1):(cout<<0);//            print rows[i] & 1<<7
		cout<<endl;//        print newline
	}
	cout<<endl;
}

bool solutionPossible(int row){
	for(int r=0; r<row; r++){
		if( (colForRow[r] == colForRow[row]) || (abs(row-r) == abs(colForRow[r]-colForRow[row])) )//conflict in queens placed in row r and row 'row'
			return false;
	}
	return true;
}
void PlaceQueen(int row){
	if(row == NumOfQueens){
		printSolution();
		return;
	}
	for(int c=0; c<NumOfQueens; c++){
		colForRow[row] = c;
		if(solutionPossible(row))
			PlaceQueen(row+1);
	}
}
int main()
{
    PlaceQueen(0);
    cout << "Hello world!"<< endl;
	getchar();
    return 0;
}
