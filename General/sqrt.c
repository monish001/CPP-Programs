
/*Ques: find square root correct upto 4 decimal digits.
 *	    ans
 *	   _________
 * div )val
 */

#include <stdio.h>
#include <conio.h>
#include <assert.h>
/*
 * Alters the aLL by omitting left most pair of 2 digits and returns this pair. Pairing is done from decimal point.
 * sets decimalFlag when decimal point crossed.
 */
double _getNextPair(long long *aLL){
	short num;
	long long dividor =100;
	do{
		num = *aLL/dividor;
		dividor *= 100;
	}while(*aLL/dividor > 0);
	dividor /= 100;
	*aLL %= dividor;
	return num;
}
int _findNewDivisorDigit(long val, long div){
	int a=9;
	for(; a>=1 ; a--){
		if(a*(div*10+a) > val)
			continue;
		else
			break;
	}
	return a;
}
int _numDigits(long long num){
	int count=0;
	for(;num!=0; num/=10){
		count++;
	}
	return count;
}
long sqrt1(double aDouble){
	aDouble = aDouble * 1e14;
	long long aLL = aDouble;
	assert(aLL >=0);
	long ans=0;
	long div = 0;
	long val = 0;//_getTwoDigits(aLL);
	int pair, pairs = (_numDigits(aLL) +1) /2;
	for(pair=0; pair < pairs; pair++){
		val *= 100; 
		val += _getNextPair(&aLL);
		
		int tmpDigit = div%10;
		div += tmpDigit;
		int newDigit = _findNewDivisorDigit(val, div);
		ans *= 10; ans += newDigit;
		div *= 10; div += newDigit;
		if(/*if divisible*/newDigit != 0)
			val -= div * newDigit;
	}
	return ans;
}
int main(){
	printf("sqrt1(5) = \t%ld\n", sqrt1(5));
	printf("sqrt1(26) = \t%ld\n", sqrt1(26));
	printf("sqrt1(123.45) = %ld\n", sqrt1(123.45));
	printf("sqrt1(12) = \t%ld\n", sqrt1(12));
	printf("sqrt1(1250) = \t%ld\n", sqrt1(1250));
	getch();
	return 0;
}
