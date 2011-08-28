//File: heapTest.c
/*MAX-HEAP
Test Case: Input array: <0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15>
*/
#include<stdio.h>
#include<stdlib.h>

#ifdef _WIN32
	#include<conio.h>
	#include"heap.c"
#elif __linux
	#include"heap.h"
#endif


int main(){
	int a[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};//16 elements
	int i, n=sizeof(a)/sizeof(int);
	for(i=0; i<n; i++)
		push(a[i]);

	puts("");
	
	for(; n>0; n--)
		printf("%d\t", pop());
#ifdef _WIN32
	getch();
#endif
	return 0;
}
