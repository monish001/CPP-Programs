//INCOMPLETE YET
//This is 8-queen problem program.
/*ALGO 1 without Back-Tracking:
bool solutionPossible(string& rows){
    for each row r in rows//LOOP1
        n_r = no. of queens in row r
        n_c = no. of queens in col r
        if not(n_r<=1 AND n_c<=1)
            return false;
    rr[] = rl[] = rows[];
    for each row i 0 to 7 //LOOP2
        rr[i]>>i
        rl[i]<<i
    for each i 0 to 7
        n1 = no. of queens in column i of rl
        nr = no. of queens in column i of rr
        if(nl>1 OR nr>1)
            return false
    return true;
}
void printSolution(string &rows){
    for each i 0 to 7
        for each j 7 to 0
            print rows[i] & 1<<7
        print newline
}
int compute8Queen(){//returns the number of solutions
    int count=0;
    string rows("00000000");//char rows[8];    memset(rows, 0, 8);
    for all q[0..7/0..0] absent AND q0 on col 0 to 7 of rows[0] AND solutionPossible(rows)
    for all q[0..7/0..1] absent AND q1 on col 0 to 7 of rows[1] AND solutionPossible(rows)
    .....
    for all q[0..7/0..7] absent AND q7 on col 0 to 7 of rows[7] AND solutionPossible(rows)
        ++count, printSolution(rows), cout<<"----------------\n";
    return count;
}
**********************************************************************
ALGO 2: with Back-Tracing:
PUSH rows and rowIndex where queen position is varied. Initially push rowIndex=0 and string rows as follows:
rows[0]=10000000
rows[1]=00000000
rows[2]=00000000
rows[3]=00000000
rows[4]=00000000
rows[5]=00000000
rows[6]=00000000
rows[7]=00000000
    num_sols = 0;
    while(stack is not empty){
        rows1, rowIndex = pop();
        if(colIndex of Q in row rowIndex < 7)
            push(rows1, rowIndex) after shifting Q in row rowIndex by 1 column right
        if SolutionPossible(rows1){
            if (rowIndex <7){
                rows[rowIndex+1] = 1<<7
                push(rows1, rowIndex)
            }else
                num_sols++, printSolution(rows1);
        }
    }
*/
#include <iostream>

using namespace std;

int main()
{

    cout << "Hello world!"<< sizeof(char) << endl;
    compute8Queen();
    return 0;
}
