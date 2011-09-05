//EDIT DISTANCE BETWEEN TWO DNA STRANDS
/*ALGORTHM:
int findMinimumCost(char* source, char* target){
    pair<short, short> cost[length dest + 1][lenght source + 1];
    intialize EACH col with row 0 with DEL
        and EACH row with col 0 with INS
    for(row 1 to length dest){
        for(col 1 to length source){

            cost[row][col-1] + del cost, cost[row-1][col] + ins cost, cost[row-1][col-1] + copy cost;
            check min of above and save cost and corresponding operation in cost[row][col]
        }
    }
    return min of i= 0 to length source {cost[lenght dest][i]}
}*/
/*
Test case:
    char *source="algori", *dest = "al";
    cout<<"Minimum Cost: "<<findMinimumCost(source, dest);
Output:
0       20      40      60      80      100     120
-       D       D       D       D       D       D

20      15      35      55      75      95      115
I       C       D       D       D       D       D

40      35      30      50      70      90      110
I       I       C       D       D       D       D

Minimum Cost: 45

Test Case:
    char *source="lagorithm", *dest = "altruistic";
    cout<<"Minimum Cost: "<<findMinimumCost(source, dest);
Output:
0       20      40      60      80      100     120     140     160     180
-       D       D       D       D       D       D       D       D       D

20      15      35      55      75      95      115     135     155     175
I       R       C       D       D       D       D       D       D       D

40      35      15      35      55      75      95      115     135     155
I       C       T       D       D       D       D       D       D       D

60      55      35      30      50      70      90      110     130     150
I       I       I       R       D       D       D       C       D       D

80      75      55      50      45      65      85      105     125     145
I       I       I       I       R       C       D       D       D       D

100     95      75      70      65      60      80      100     120     140
I       I       I       I       I       R       D       D       D       D

120     115     95      90      85      80      75      95      115     135
I       I       I       I       I       I       C       D       D       D

140     135     115     110     105     100     95      90      110     130
I       I       I       I       I       I       I       R       D       D

160     155     135     130     125     120     115     110     105     125
I       I       I       I       I       I       I       C       R       D

180     175     155     150     145     140     135     115     125     120
I       I       I       I       I       I       C       T       I       R

200     195     175     170     165     160     155     135     130     140
I       I       I       I       I       I       I       I       R       I

Minimum Cost: 140
*/
#include <cstring>
#include <iostream>
using namespace std;
#define INS 'I'
#define DEL 'D'
#define COP 'C'
#define REP 'R'
#define TWI 'T'
#define KIL 'K'
#define INS_COST 20
#define DEL_COST 20
#define COP_COST 15
#define REP_COST 15
#define TWI_COST 15
#define KIL_COST 15

struct cell{
    short cost;
    char operation;
};
template<class T>
T** make2D_mat(int r, int c, T default_val = NULL){
    T** val = new T*[r];
    for(int i=0; i<r; i++){
            val[i] = new T[c];
            for(int j=0; j<c; j++)
                    val[i][j] = default_val;
    }
    return val;
}

short findMinimumCost(char* source, char* dest){

    cell dummy; dummy.cost=-1; dummy.operation=-1;

    short dest_length = strlen(dest);
    short source_length = strlen(source);
    cell** table = make2D_mat(dest_length + 1, source_length + 1, dummy);

//intialize EACH col with row 0 with DEL and EACH row with col 0 with INS
    table[0][0].cost = 0;
    table[0][0].operation = '-';
    for(int col = 1; col<= source_length; col++){
        table[0][col].cost = table[0][col-1].cost + DEL_COST;
        table[0][col].operation = DEL;
    }
    for(int row = 1; row<= dest_length; row++){
        table[row][0].cost = table[row-1][0].cost + INS_COST;
        table[row][0].operation = INS;
    }

/*    for(row 1 to length dest)
        for(col 1 to length source)
            table[row][col-1] + DEL_COST, table[row-1][col] + INS_COST, table[row-1][col-1] + COP_COST;
            check min of above and save cost and corresponding operation in cost[row][col]
            get min and switch (operation) -> initialize table[row][col] with that.*/
    for(short row=1; row<=dest_length; row++){
    for(short col=1; col<=source_length; col++){
//compute least cost operation for table[row][col]
//        cout<<"Cell "<<row<<" "<<col<<": ";
//        cout<<"Cop cost: "<<table[row-1][col-1].cost + COP_COST;
//        cout<<"  Ins cost: "<<table[row-1][col].cost + INS_COST;
//        cout<<"  Del cost: "<<table[row][col-1].cost + DEL_COST;
        short cop_cost = (source[col-1] == dest[row-1])?(table[row-1][col-1].cost + COP_COST):(999);
        short ins_cost = table[row-1][col].cost + INS_COST;
        short del_cost = table[row][col-1].cost + DEL_COST;
        short rep_cost = table[row-1][col-1].cost + REP_COST;
        short twi_cost = (row>1 && col>1 && source[col-1] == dest[row-2] && source[col-2] == dest[row-1])?(table[row-2][col-2].cost + TWI_COST):(999);
        short oper = 0;
        if(cop_cost <= ins_cost && cop_cost <= del_cost && cop_cost <= rep_cost && cop_cost <= twi_cost)
            oper = COP;
        else if(ins_cost <= del_cost && ins_cost <= rep_cost && ins_cost <= twi_cost)
            oper = INS;
        else if(del_cost <= rep_cost && del_cost <= twi_cost)
            oper = DEL;
        else if(rep_cost <= twi_cost)
            oper = REP;
        else
            oper = TWI;
//save data in table[row][col]
        table[row][col].operation = oper;
        switch(oper){
            case COP:
                table[row][col].cost = cop_cost;
//                cout<<"\tCOP\n";
                break;
            case DEL:
                table[row][col].cost = del_cost;
//                cout<<"\tDEL\n";
                break;
            case INS:
                table[row][col].cost = ins_cost;
//                cout<<"\tINS\n";
               break;
            case REP:
                table[row][col].cost = rep_cost;
//                cout<<"\tREP\n";
                break;
            case TWI:
                table[row][col].cost = twi_cost;
//                cout<<"\tTWI\n";
                break;
            default:
                cout<<"ERROR: NO OPERATION SELECTED";
                return -1;
        }
    }
    }

//show table
    for(short row=0; row<=dest_length; row++){
    for(short col=0; col<=source_length; col++){
        cout<<table[row][col].cost<<"\t";
    }
//    cout<<"\n";
    for(short col=0; col<=source_length; col++){
        cout<<table[row][col].operation<<"\t";
    }
    cout<<"\n";
//    cout<<"\n";
    }

//return minimum cost
    short minCostCol=0, min_cost=table[dest_length][0].cost;
    for(short temp, col = 1; col<=source_length; col++){
        temp = table[dest_length][col].cost;
        if(temp < min_cost){
            min_cost = temp;
            minCostCol = col;
        }
    }
    if(minCostCol != source_length){
//min_cost = min(min_cost+KIL_COST, table[dest_length][source_length].cost);
        min_cost += KIL_COST;
        if(min_cost > table[dest_length][source_length].cost)
            min_cost = table[dest_length][source_length].cost;

    }
    return min_cost;
}
int main()
{
    char *source="lagorithm", *dest = "altruistic";
    cout<<"Minimum Cost: "<<findMinimumCost(source, dest);
    return 0;
}
