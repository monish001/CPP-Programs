#define AND &&
#define COND (a>25 AND a<50)
#include<stdio.h>
#define MAX(x,y) (x)>(y)?(x):(y)
#define PRINT(int) printf("int = %d ",int)
int main(){

int a[] ={ 11,22,37,48,59,69,97};
char c[] = {' a','x','h','o','k'};
printf("%d\t %d ", (&a[3]-&a[0]),(&c[3]-&c[0]));

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
fflush(stdin);
 return 0, getchar();
    }
 
