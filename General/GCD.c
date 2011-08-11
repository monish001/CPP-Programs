//filename: GCD.c
//to find GCD or HCF of two numbers
#include<stdio.h>

main(){
	int a=-1, b=-1, ans;
	puts("Enter 2 positive integers.. ");
	scanf("%d %d", &a, &b);
	for(; a && b; ){
		(a<b)?(b=b%a):(a = a%b);
	}
	ans = (a>b)?(a):(b);
	printf("%d %d %d", a, b, ans);
	
	fflush(stdin);
	getchar();
	return 0;
}
