#include<stdio.h>


//#error some wrong condition
#define PIsd 3535
void test(int a, int b){
	printf("%d %d",a,b);
}
main(){
 int asa[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    printf("%u, %u, %u\n", asa[0]+1, *(asa[0]+1), *(*(asa+0)+1));


const sc = -11;
    const int sd = 34;
    printf("%d, %d\n", sc, sd);
        getchar();

    int m[15][10] = {2,3,4,5,45,45,45,45,4,5,45,4,5,45,45};
    printf("%d %u %u %u %u %u %u", sizeof(m), m+1,&m, m, m[0], &m[0], &m[0][0]);
    getchar();

    printf("%d", (unsigned int)10 + (signed int)0xffff0000);
    getchar();

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
