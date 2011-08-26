#include<stdio.h>
int main(){
    int OrigDays, m, d, days[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, temp;
    scanf("%d", &OrigDays);
    m = (OrigDays/365)*12;
    d = OrigDays%365;
    for(temp=0; temp<12; temp++){
             if(d < days[temp]) break;
             d -= days[temp]; ++m;
    }
    printf("%d months and %d days\n",m,d);

    fflush(stdin);
    return 0,    getchar();
}
