//Question: Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and pennies (1 cent), write code to calculate the number of ways of representing n cents.
//WRONG PROGRAM
//WRONG PROGRAM
//WRONG PROGRAM
//WRONG PROGRAM
#include<stdio.h>
int main(){
    int n=0;
	do{
		int i, ans=1;
		scanf("%d", &n);
		if(n>=5)
		for(i=5; i<=n; i++){
			ans += ((i%25==0)?(1):(0)) + ((i%10==0)?(1):(0)) + ((i%5==0)?(1):(0));
		}
		printf("Ans: %d\n", ans);
	}while(n);

//	fflush(stdin);
	getchar();
    return 0;
}
