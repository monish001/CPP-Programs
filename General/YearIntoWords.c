//COMPLETE
#include<stdio.h>
#include<conio.h>

/**
*translateAndPrint(int): Prints the non-negative number upto 99 as words
*/
void translateAndPrint(int n){
	if(n<20){
		switch(n){
			case 1: printf("one "); break;
			case 2: printf("two "); break;
			case 3: printf("three "); break;
			case 4: printf("four "); break;
			case 5: printf("five "); break;
			case 6: printf("six "); break;
			case 7: printf("seven "); break;
			case 8: printf("eight "); break;
			case 9: printf("nine "); break;
			case 10: printf("ten "); break;
			case 11: printf("eleven "); break;
			case 12: printf("twelve "); break;
			case 13: printf("thirteen "); break;
			case 14: printf("fourteen "); break;
			case 15: printf("fifteen "); break;
			case 16: printf("sixteen "); break;
			case 17: printf("seventeen "); break;
			case 18: printf("eighteen "); break;
			case 19: printf("nineteen "); break;
		}
		return;
	}
	switch(n/10){
		case 2: printf("twenty "); break;
		case 3: printf("thirty "); break;
		case 4: printf("fourty "); break;
		case 5: printf("fifty "); break;
		case 6: printf("sixty "); break;
		case 7: printf("seventy "); break;
		case 8: printf("eighty "); break;
		case 9: printf("ninety "); break;
	}
	translateAndPrint(n%10);
}
int main(){
	//char year[500]={0};
	char input[5]={0};
	printf("yyyy: ");
	scanf("%s", &input);
	int low = (input[3]-48)+ 10*(input[2]-48);
	int med = input[1]-48;
	int high = input[0]-48;
//	printf("%d%d", high, low);
	translateAndPrint(high);
	if(high!=0) fputs("thousand ", stdout);
	translateAndPrint(med);
	if(med!=0) fputs("hundred ", stdout);
	if(low!=0) fputs("and ", stdout);
	translateAndPrint(low);
	puts("");
	getch();
}
