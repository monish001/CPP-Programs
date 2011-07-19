//Tested on Dev-C++ in Win XP
#include<stdio.h>
#include<stdlib.h>

int main(){
	static int temp;
	static int n = (printf("Enter any non-negative integer.."), scanf("%d", &temp), temp);
	static int fac=1;
	
    if(n){
		fac *= n--;
		main();
    }else{
		printf("%d", fac);
		fflush(stdout);
		fflush(stdin);
		getchar();
	}
	return 0;
}
