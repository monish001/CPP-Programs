//File: heap.h
//MAX-HEAP
extern int top;
extern int capacity;
extern int *arr;

int *enhanceCapacity();
void swap(int*, int*);
void maxHeapifyAfterPush(int);//Places arr[top] to its correct position
void push(int);
void maxHeapifyAfterPop(int);//Places root to its correct position
int pop();
