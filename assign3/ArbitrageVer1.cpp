/*
Test case:
Enter no. of currencies3
From1 to 2the rate is0.6853
From1 to 3the rate is0.005290
From2 to 1the rate is1.4599
From2 to 3the rate is0.007721
From3 to 1the rate is189.050
From3 to 2the rate is129.520

Output:-
The path is from2to 3
 The maximum profit is 1.00729

*/
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    int n,i,j,k,s=-1,l,m;
    float rate[10][10], cost[10][10], A[10][10],sum=3435.00;
    cout<<"Enter no. of currencies";
    cin>>n;
    for(i=1;i<=n;i++) //Input the exchange rate of currencies
    for(j=1;j<=n;j++)
    {
        if(i==j)
        {
            rate[i][j]=1;
            cost[i][j]=s*log(rate[i][j]);
            continue;
        }
        //exchange rate to similar currency is 1
        //all other rates we have to enter
        cout<<"From"<<i<<" to "<<j<<"the rate is";
        cin>>rate[i][j];
        cost[i][j]=s*log(rate[i][j]);  //we will convert this problem into all pair shortest path problem
    }
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        A[i][j]=cost[i][j];

    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        if(A[i][j]>(A[i][k]+A[k][j]))
            A[i][j]=A[i][k]+A[k][j];
    }
    //Here we find a cycle with shortest path
    //this cyce will go from l to m and back to l
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++){
        if(i<j){
            if(sum>A[i][j]+A[j][i])
            sum=A[i][j]+A[j][i];
            l=i;
            m=j;
        }
    }
    cout<<"\n The path is from"<<l<<"to "<<m;
    cout<<"\n The maximum profit is "<<exp(s*sum);
    getch();
    return 0;
}
