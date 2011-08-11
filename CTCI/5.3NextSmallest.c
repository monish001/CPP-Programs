//Given an integer, print the next smallest and next largest number that have the same number of 1 bits in their binary representation.
//only smallest is done. code for next largest is incomplete.
#include<stdio.h>
#include<string.h>
int int_bits = sizeof(int)*8;
void printBinary(unsigned n){
	int i;
	char *a = (char*)malloc(int_bits+1);
	a[int_bits]='\0';
	printf("n %05d: ",n);
	for(i=0; i< int_bits; i++){
		a[int_bits-1-i] = ((n%2)?('1'):('0'));
		n>>=1;
	}
	puts(a);
}
int main(){
	int i=0,n, N, num_1s;
	scanf("%d",&N);
	n=N;
	//printBinary(n);
	//look for 0 from index = 0 onwards in n
	for(i=0; i < int_bits; i++){
		if( (n & (1<<i)) == 0){
			 printf("0 at %d\nBits in an int: %d\n", i, int_bits); num_1s = i; break;}
	}
	//look for 1 from index = prev_found_index_of_0 + 1
	for(; i < int_bits; i++){
		if( (n & (1<<i)) != 0){
			 printf("1 at %d\n", i); break;}
	}
	//Now n at ith and i-1th bits is 10

	if(i == int_bits){
		puts("Smaller no. not possible");
	}else{
	//make the i and i+1th bit 0 0
		int mask = 3 << i-1;
		mask = ~mask;
		n &= mask;
	//put 01 in n on ith and i-1th bits
		mask = 1<<i-1;
		n |= mask;

	//put 000 i-1 times in right of n
		int mask1 = (-1 << (i-1));
		n &= mask1;
	//put 1111..(num_1s times)..0000 in the i-1 right most places
		unsigned mask2 = (((unsigned)-1) >> (int_bits - num_1s));
		mask2 <<= ((i-1)-num_1s);
		//printBinary(mask2);
		n |= (mask2);

		printBinary(N);
		printBinary(n);
		printf("Just smaller new is : %d\tmask is: %d\n", n, mask);
	}
/*
	n=N;
	for(i=0; i < int_bits; i++){
		if( (n & (1<<i)) != 0){
			 printf("1 at %d\n", i); break;}
	}
	for(; i < int_bits; i++){
		if( (n & (1<<i)) == 0){
			 printf("0 at %d\n", i); break;}
	}
	if(i == int_bits){
		puts("Larger no. not possible");
	}else{
		int mask = 3 << i-1;
		mask = ~mask;
		n &= mask;
		mask = 2<<i-1;
		n |= mask;
		printf("Just larger is : %d\n", n);
	}
*/
	fflush(stdin);
    return 0, getchar();
}
