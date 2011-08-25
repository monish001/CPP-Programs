//Question: Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and pennies (1 cent), write code to calculate the number of ways of representing n cents.
#include<stdio.h>
int findWays(int n, int coinType){
	int nextCoinType;
	switch(coinType){
		case 25:
			nextCoinType = 10;
			break;
		case 10:
			nextCoinType = 5;
			break;
		case 5:
			nextCoinType = 1;
			break;
		case 1:
			return 1;
	}
	int ways = 0, numOfCoins;
	for(numOfCoins = 0; n >= numOfCoins*coinType; numOfCoins++){
		ways = ways + findWays((n-numOfCoins*coinType), nextCoinType);
	}
	if(n == numOfCoins*coinType)
		ways++;
	return ways;
}
int main(){
    int n=0;
	do{
		scanf("%d", &n);
		printf("Ans: %d\n", findWays(n, 25));
	}while(n);

//	fflush(stdin);
	getchar();
    return 0;
}
