//INCOMPLETE
//File: LongestIncreasingSubsequence.c
/*
Test Case: Input array: <0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15>
Output: Any one: <0, 2, 6, 9, 13, 15> OR <0, 4, 6, 9, 11, 15>
*/
#include<stdio.h>
#include<conio.h>
typedef struct record{
	int val;
	int length;
} record;
int lengthLCS(int a[]){
	int i, n = sizeof(a)/sizeof(int);
	if(n<1) return 0;
	if(n==1) return 1;
	push(record(a[0], 1));//push operation of container sorted in ascending order by 'length'
	for(i=1; i<n; i++){
		int j;
		for(j=i-1; j>=0; j--)//find appropriate location (in 0 to i-1) to insert record i
			if(a[i] >= read(j))
				break;
		record tmp={a[j], 	};
		int k;
		for(k=i-1; k>=j; k--)
			r[k+1] = r[k];
		r[j] = record();
		
	}
}
int main(){
	int a[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};//16 elements
	int ans[16];
	memset(ans, -1, sizeof(int)*16)
	printf("%d", lengthLCS(a, ans));
	getch();
	return 0;
}
