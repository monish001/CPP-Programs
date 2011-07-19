#include<stdio.h>


//#error some wrong condition

void test(int a, int b){
	printf("%d %d",a,b);
}
main(){
	int e=20;
	test(e, ++e);
	getchar();
	
	
	
	char *c="monish gupta";
	printf("%d",sizeof(c));
	char a[]="monish gupta";
	printf("%d",sizeof(a));
	char * const b="monish gupta";
	printf("%d",sizeof(b));
	char const *d="monish gupta";
	printf("%d",sizeof(d));
	getchar();
	
	
	printf("%d",sizeof(void *));
	printf("%d",sizeof(int *));
	printf("%d",sizeof(char *));
	printf("%d",sizeof(struct any_name *));
	getchar();
	
	
	unsigned long f=-1;
	long g = 1;
	if(g<f && f>g)
		printf("it is working");
	getchar();
}
