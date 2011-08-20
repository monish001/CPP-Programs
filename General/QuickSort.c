//Filename: QuickSort.c

#include<stdio.h>
void swap(int a[], int i1, int i2){
	if(i1==i2) return;
	a[i1] ^= a[i2] ^= a[i1] ^= a[i2];
}
void printArray(int a[]){
    int n = 5;//sizeof(a)/sizeof(int);
    int i;
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    puts("");
}
int partition(int a[], int left, int right, int pivotIndex){
	int p_val= a[pivotIndex];
	swap(a, right, pivotIndex);
	int i, storeIndex = left;
	for(i=left; i<=right-1; i++){
		if(a[i] < p_val){
			swap(a, storeIndex, i);
			storeIndex++;
		}
	}
	swap(a, storeIndex, right);
//	printf("%d : ", a[storeIndex]); printArray(a);
	return storeIndex;
}
void quickSort(int a[], int left, int right){
	if(left >= right-1)
		return;
	int pivotIndex = partition( a, left, right, left + (right-left)/2 );
	quickSort(a, left, pivotIndex-1);
	quickSort(a, pivotIndex+1, right);
}

int main(int argc, char* argv){
	int a[] = {5, 8, 7, 3, 1};
	quickSort(a, 0, 4);
	printArray(a);
	return getch();
}
