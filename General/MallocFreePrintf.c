#include<stdio.h>
#include <stdarg.h>
/*void * myMalloc(size_t size){
	void *p=NULL;
	//allocate memory
	(p)?printf("In malloc: Memory allocated"):printf("In malloc: Memory allocation failed");
	return p;
}
void myFree(void *p){}*/
int myPrintf(char* fmt, ...){
	va_list ap;/*points to each unnamed argument in turn*/
	va_start(ap, fmt);/* make ap point to 1st unnamed arg */
	
	char* c;
	for(c = fmt; *c; c++){
		if(*c != '%'){
			putchar(*c);
			continue;
		}
		switch(*++c){
			case 'd': printf("%d", va_arg(ap, int)); break;
			case 'f': printf("%f", va_arg(ap, double)); break;
			case 's': printf("%s", va_arg(ap, char *)); break;
			default: putchar(*c); break;
		}
	}
	va_end(ap);/* clean up when done */
}
main(){
/*	int *p = (int*)myMmalloc(2*sizeof(int));
	if(!p)
		return;
	p[0]=10; p[1]=20;
	myFree(p);
	p[0]=10; p[1]=20;*/
	myPrintf("String: %s\nInt: %d\nFloat: %f\n", "Hello, World", 1234, 12.3490);
	getchar();
}
