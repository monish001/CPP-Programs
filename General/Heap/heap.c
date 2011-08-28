//File: heap.c
//MAX-HEAP
#include"heap.h"
int top=-1;
int capacity = 0;
int *arr;

int *enhanceCapacity(){
    if(capacity == 0){
		arr = (int*) malloc (sizeof(int));
		capacity++;
		return arr;
	}
	capacity *= 2;
	arr = (int*)realloc(arr, capacity*sizeof(int));
	return arr;
}
void swap(int*p, int*q){
	int t = *p; 
	*p = *q;
	*q = t;
}
void maxHeapifyAfterPush(int i){//Places arr[top] to its correct position
	if(i<1)
		return;
	if(arr[i]>arr[(i-1)/2]){
		swap(&arr[i], &arr[(i-1)/2]);
		maxHeapifyAfterPush((i-1)/2);
	}
}
void push(int val){
	if(top+1 == capacity && enhanceCapacity()==(int*)0){
		puts("No more memory available");
		return;
	}
	arr[++top] = val;
	maxHeapifyAfterPush(top);	
}
void maxHeapifyAfterPop(int i){//Places root to its correct position
	if(i>=top || 2*i+1>top)
		return;
	int index;
	if(2*i+2 > top)
		index = 2*i+1;
	else{
		if(arr[2*i+1]<arr[i] && arr[2*i+2]<arr[i])
			return;
		index = ((arr[2*i+1]>arr[2*i+2])?(2*i+1):(2*i+2));
	}
	if(arr[i] < arr[index]){
        swap(&arr[i], &arr[index]);
		maxHeapifyAfterPop(index);
	}
}
int pop(){
	if(top == -1){
		puts("Heap Empty");
		return -1;
	}
	int temp = arr[0];
	arr[0] = arr[top--];
	maxHeapifyAfterPop(0);
	return temp;
}
