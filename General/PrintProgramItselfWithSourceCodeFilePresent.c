#include<stdio.h>
int main(){
	FILE *fp = fopen(__FILE__, "r");
	if(!fp)
		return 1;
	char c;
	for(c  = getc(fp); c!= EOF; c= getc(fp)){
		putchar(c);
	}
	getchar();
	return 0;
}