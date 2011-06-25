#ifndef SCHAT_REGISTER_C
#define SCHAT_REGISTER_C
//SChat_register.h
#define true 1
#define false 0
#include<stdio.h>
#include<stdlib.h>
void Error(const char *msg){
    perror(msg);
    exit(1);
}

typedef short bool;
int* ar;//= (int*) malloc(sizeof(int));
int maxIndex;// = 0;
int top;// = -5;
bool lock;// = false;

void getRegisteredList(){
	int i;
	for(i=0; i<=top; i++)
		printf("%d\t", ar[i]);
	printf("\n");
}
//call this before using any other function of this library
void init(){
	ar = (int*) malloc(sizeof(int));
	if(ar == NULL)
		Error("malloc error in init");
	top = -1;
	maxIndex = 0;
	lock = false;
}

int registerMe(int fd){
printf("In registerMe\n");
	while(lock)
		printf("lock busy\n");
	lock = true;
	int retIndex=-1;
	if(top == maxIndex){
		ar = realloc(ar, (maxIndex+1)*2 * sizeof(int));
		if(ar == NULL)
			Error("realloc error in register");
		maxIndex = (maxIndex+1)*2 - 1;
	}
	//POS FROM 0 TO top are filled on sorted order already. Use ++top and insert fd.
	//ar[++top] = fd;
	int i;
	for(i=top; i>0; i--){
		if(ar[i] > fd)
			ar[i+1] = ar[i];
		else{
			retIndex = i+1;
			ar[retIndex] = fd;
			break;
		}
	}
	if(top <1){
		ar[top+1] = fd;
		retIndex = top+1;
	}
	top++;
	lock = false;
	return retIndex;
}

int isRegistered(int fd){
//	test for top =0, =1, =n
	//search fd in sorted array ar using binary search
	int ans = -1;
/*	int b=0, e=top;
	do{
printf("In isRegistered\n");
		int mid = (b+e)/2;
		if(ar[mid] == fd){
			ans = mid;
			break;
		}else if(ar[mid] > fd)
			e = mid-1;
		else
			b = mid+1;
	}while(b<e);*/
int i;
for(i=0; i<=top; i++){
	if(ar[i] == fd){
		ans = i;
		break;
	}
}
	return ans;
}

void unRegister(int fd){
	int x = isRegistered(fd);
	if(x== -1)
		return;
	while(lock)
		printf("lock busy\n");
	lock = true;
	int i;
	for(i=x+1; i<=top; i++){
		ar[i-1] = ar[i];
	}	
	--top;
	lock = false;
}

#endif // SCHAT_REGISTER_C
