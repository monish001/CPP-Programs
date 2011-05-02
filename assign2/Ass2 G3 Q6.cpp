#include<iostream>
using namespace std;

/*Question 6. Write an algorithm to implement the bucket sort algorithm.
function bucket-sort(array, n) is
  buckets <- new array of n empty lists
  for i = 0 to (length(array)-1) do
    insert array[i] into buckets[msbits(array[i], k)]
  for i = 0 to n - 1 do
    next-sort(buckets[i])
  return the concatenation of buckets[0], ..., buckets[n-1]
Test Case:
    int *a = new int[10];
    for(int i=0; i<10; i++)
        a[i]=20-i;
    cout<<"Initial Sequence:\n";
    for(int i=0; i<10; i++)
        cout<<a[i]<<" ";
    bucketSort(a, 10);
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
    bucketSort(a, 10);
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
typedef int T;
class array{
	T *ar;
	int topIndex,sizeIndex;
	public:
	array():ar(new T[2]),topIndex(-1), sizeIndex(1){}
	array(int N):topIndex(N-1),sizeIndex(N-1),ar(new T[N]){}
	unsigned count(){
		return topIndex+1;
	}
	bool push(T item){
		if(topIndex == sizeIndex){
			sizeIndex = (sizeIndex+1)*2-1;
			T *temp = new T[sizeIndex+1];
			for(int i=0; i<=topIndex; i++)				temp[i]=ar[i];//copy count-1 elements
			delete[] ar;
			ar=temp;
		}
		ar[++topIndex]=item;
	}
	T& operator[](int index){
		if(index<0){
			cout<<"ERROR: Array Underflow\nProgram is terminating. Press any key.\n";
			fflush(stdin);
			getchar();
			exit(0);
		}
		if(index>topIndex){
			cout<<"ERROR: Array Overflow\nProgram is terminating. Press any key.\n";
			fflush(stdin);
			getchar();
			exit(0);
		}
		return ar[index];	
	}
};
int findIndexInN(array a, int ind, int item){
	for(int i=0; i<=ind; i++)
		if(a[i]>=item) //for increasing order list
			return i;
	return ind+1;
}
void InsertionSort(array a, int n){
	int item, pos;
	for(int i=1; i<n; i++){//0th index element already sorted, so i <- 1 to n-1
		item = a[i];
		pos = findIndexInN(a, i-1, item);
		for(int j=i; j>pos ; j--)
			a[j] = a[j-1];
		a[pos]=item;
	}
}
void bucketSort(int* a, int n){//Assuming numbers to be in the range of 100
	array bucket[10];
	for(int i=0; i<n; i++)
		bucket[a[i]/10].push(a[i]);
	int index=0,num;
	for(int i=0; i<9; i++){
		num = bucket[i].count();
		InsertionSort(bucket[i], num);
		for(int j=0; j<num; j++,index++)
			a[index] = bucket[i][j];
	}
}