//filename: FunctionReturningArray.c
//NOT WORKING
#include<stdio.h>
#include<conio.h>

char* func(char* p1[])[]
{
	char* p[]={"dfghj", "fghjk", "CVBNM"};
      printf("%d", sizeof(p));
	return p;
}
int main(){
	char* p[]={"dfghj", "fghjk", "CVBNM"};
      printf("%d", sizeof(p));
	func(p);
	getch();
	return 0;
}

