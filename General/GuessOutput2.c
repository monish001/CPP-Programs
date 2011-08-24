#define AND &&
#define COND (a>25 AND a<50)
//#include<stdio.h>
#define MAX(x,y) (x)>(y)?(x):(y)
#define PRINT(int) printf("int = %d ",int)

int fun( int n)
{
int i;
for(i=0;i<=n;i++)
fun(n-i);
printf(" well done");
getchar();
}
#include<string.h>
char *f()
{char *s=malloc(8);
strcpy(s,"goodbye");}

int main(int c, char* arg[]){


/*unsigned char a = 255;
if(a == (char)(-1))
    return 1;*/
    
/*struct astruct{
    char aint;
};
struct astruct obj;
int arr[] = {12, 14, 15, 23, 45};
printf("%u %u %u\n",1+ arr, 1+ &arr, &arr[0]);
printf("%u %u\n",&obj, &(obj.aint));*/

    /*int a = 5;
    switch(a)
    {
    case 1:
    printf("First");

    case 2:
    printf("Second");

    case 3 + 2:
    printf("Third");

    case 5:
    printf("Final");
    break;

    }*/

/*int i=3;
while(i--)
{
int i=100;
i--;
printf("%d..",i);
}*/

/*int rows=3,colums=4;
int a[rows][colums]={1,2,3,4,5,6,7,8,9,10,11,12};*/


/*char *f();
printf("%c",*f()='A');*/

/*&int a=1, b=2, c=3, *pointer;
pointer=&c;
a=c/ *pointer;
b=c;
printf("a=%d b=%d",a,b);*/

//int *x[]();

/*int *ptr[100],i;
for(i=0;i<100;i++) {
    ptr[i]=(int *)malloc(10*sizeof(int));
}*/

/*typedef struct{
    char *asd;
    nodeptr next;
}* nodeptr;*/

/*int a=10, b=20;
printf("%d %d", a, b);
a^=b^=a^=b;
printf("%d %d", a, b);*/

//fun(1);

/*unsigned char i=0x80;// a character variable which is 1 byte long
printf("i=%d",i<<1);*/

/*int *ptr[][100];
char c='a';
printf("%d %d", sizeof(c),sizeof('a'));*/

/*int x=9;
if(x++) printf("%d", x);*/

//int a=2, b=3;
//printf(" %d ", a+++b);

//typedef struct{char *c;nodeptr next;} * nodeptr;

/*struct s1 {int i; };
struct s2 {int i; };
struct s1 st1;
struct s2 st2;
st1.i =5;
st2 = st1;
printf(" %d " , st2.i);*/

/*int a[] ={ 11,22,37,48,59,69,97};
char c[] = {' a','x','h','o','k'};
printf("%d\t %d ", (&a[3]-&a[0]),(&c[3]-&c[0]));*/

/* int x,y,z;
 x=03;y=02;z=01;
 PRINT(x^x);
 z<<=3;PRINT(x);
 y>>=3;PRINT(y); */

/*int a=10,b=20;
 a>=5?b=100:b=200;
 printf("%d\n",b);*/

/*int i=10,j=5,k=0, l=0;
 k= MAX(i++,++j);
 printf("%d %d %d",i,j,k);*/

/*int i=10,j=5,k=0, l=0;
 if(i++>++j) k = i++;
 else k = ++j;
 printf("%d %d %d",i,j,k);*/

/*int a=30;
if(COND)
	puts("true");
else
	puts("false");*/


/*typedef (static int) *i;
  static int j;
  i a = &j;
  printf("%d", *a);*/

/*char *str = "junk";
scanf ("%[A telephonic girl]", str);
printf ("%s\n", str);*/

/*int x, y;
printf ("%d\n", scanf ("%d %d", &x, &y));*/

/*t x = 6;
x = x ^ x;
printf ("%d\n", x);*/


/*char*str;
scanf ("%s", str);

switch (str) {
case "Sun":
printf ("Sunday\n");
break;
case "Mon";
printf("Monday\n");
break;
}*/
//fflush(stdin);
 return 0;
    }

