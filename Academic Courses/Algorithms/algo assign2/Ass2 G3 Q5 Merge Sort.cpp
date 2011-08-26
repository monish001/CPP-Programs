#include<iostream>
using namespace std;

/*Question 5. Write an algorithm to implement the merge sort algorithm.
Test Case:
    int *a = new int[10];
    for(int i=0; i<10; i++)
        a[i]=20-i;
    cout<<"Initial Sequence:\n";
    for(int i=0; i<10; i++)
        cout<<a[i]<<" ";
    mergeSort(a, 0, 9);
    cout<<"\nSorted Sequence:\n";
    for(int i=0; i<10; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    delete[] a;
Output:
    Initial Sequence:
    20 19 18 17 16 15 14 13 12 11
    Sorted Sequence:
    11 12 13 14 15 16 17 18 19 20
Test Case:
    int *a = new int[10];
    for(int i=0; i<10; i++)
        a[i]=20+i;
    cout<<"Initial Sequence:\n";
    for(int i=0; i<10; i++)
        cout<<a[i]<<" ";
    mergeSort(a, 0, 9);
    cout<<"\nSorted Sequence:\n";
    for(int i=0; i<10; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    delete[] a;
Output:
    Initial Sequence:
    20 21 22 23 24 25 26 27 28 29
    Sorted Sequence:
    20 21 22 23 24 25 26 27 28 29	
*/
//combines A
void combine(int *A, int beg, int beg2, int end){
	int x=beg, y=beg2, i=0;
	int *ar = new int[end-beg+1];
	while(x<beg2 && y<=end){
		if(A[x]<A[y]){
			ar[i]=A[x];
			x++;
		}else if(A[x]>A[y]){
			ar[i]=A[y];
			y++;
		}else{
			ar[i]= A[x];
			i++, x++;
			ar[i]=A[y];
			y++;
		}
		i++;
	}
	for(;x<beg2; x++, i++)
		ar[i] = A[x];
	for(;y<=end; y++, i++)
		ar[i] = A[y];
	--i;//now points to last element
	for(int j=end; i>=0; --i, j--)
		A[j]=ar[i];
}
void mergeSort(int *A, int beg, int end){
	if(end-beg == 0 )//only one element
		return;
	int mid = (beg+end)/2;	//Divide
	mergeSort(A, beg, mid);	//Conquer
	mergeSort(A, mid+1, end);	//Conquer
	combine(A, beg, mid+1, end);	//Combine
}