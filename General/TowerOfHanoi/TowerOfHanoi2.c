#include<stdio.h>
void move(int m, int d[], int* index_d, int e[], int* index_e, int f[], int* index_f)
{
	if(m==1)//move (1,d,e,f);
	{
		e[*index_e] = d[*index_d - 1];
		(*index_e)++;
		(*index_d)--;	
	}
	else
	{//move(n-1,d,f,e) 	//mov(1,d,e,f)	//mov(n-1,f,e,d)
		move(m-1, d, index_d, f, index_f, e, index_e);
		showStatus(index_d, index_e, index_f, d, e, f);
		move(1, d, index_d, e, index_e, f, index_f);
		showStatus(index_d, index_e, index_f, d, e, f);
		move(m-1, f, index_f, e, index_e, d, index_d);	
		//showStatus(index_d, index_e, index_f, d, e, f);
	}
}
int *A, *B, *C;
showStatus(int *index_a, int* index_b, int* index_c, int a[], int b[], int c[])
{
	int i=0;
	int ndex_a = *index_a;
	int ndex_b = *index_b;
	int ndex_c = *index_c;
	if(A == a)
	{
		printf("\n%d : ",ndex_a);
		for(i=0; i<ndex_a; i++)//for(; (ndex_a)>0; (ndex_a)--)
			printf("%d ",a[i]);//a[(ndex_a)-1]);
		if( B == b)// && C == index_c))
		{
			printf("\n%d : ",ndex_b);
			for(i=0; i<ndex_b; i++)//for(; ndex_b>0; (ndex_b)--)
				printf("%d ",b[i]);//ndex_b-1]);
		
			printf("\n%d : ",ndex_c);
			for(i=0; i<ndex_c; i++)//for(; ndex_c>0; (ndex_c)--)
				printf("%d ",c[i]);//ndex_c-1]);
		}
		else
		{
			printf("\n%d : ",ndex_c);
			for(i=0; i<ndex_c; i++)//for(; ndex_c>0; (ndex_c)--)
				printf("%d ",c[i]);//ndex_c-1]);
			printf("\n%d : ",ndex_b);
			for(i=0; i<ndex_b; i++)//for(; ndex_b>0; (ndex_b)--)
				printf("%d ",b[i]);//ndex_b-1]);
		
		}
	}
	else if(A == b)
	{
		printf("\n%d : ",ndex_b);
		for(i=0; i<ndex_b; i++)//for(; (ndex_a)>0; (ndex_a)--)
			printf("%d ",b[i]);//a[(ndex_a)-1]);
		if( B == a)// && C == index_c))
		{
			printf("\n%d : ",ndex_a);
			for(i=0; i<ndex_a; i++)//for(; ndex_b>0; (ndex_b)--)
				printf("%d ",a[i]);//ndex_b-1]);
		
			printf("\n%d : ",ndex_c);
			for(i=0; i<ndex_c; i++)//for(; ndex_c>0; (ndex_c)--)
				printf("%d ",c[i]);//ndex_c-1]);
		}
		else
		{
			printf("\n%d : ",ndex_c);
			for(i=0; i<ndex_c; i++)//for(; ndex_c>0; (ndex_c)--)
				printf("%d ",c[i]);//ndex_c-1]);
			printf("\n%d : ",ndex_a);
			for(i=0; i<ndex_a; i++)//for(; ndex_b>0; (ndex_b)--)
				printf("%d ",a[i]);//ndex_b-1]);
		
		}
		
	}
	else//A == c is true
	{
		printf("\n%d : ",ndex_c);
		for(i=0; i<ndex_c; i++)//for(; (ndex_a)>0; (ndex_a)--)
			printf("%d ",c[i]);//a[(ndex_a)-1]);
		if( B == b)// && C == index_c))
		{
			printf("\n%d : ",ndex_b);
			for(i=0; i<ndex_b; i++)//for(; ndex_b>0; (ndex_b)--)
				printf("%d ",b[i]);//ndex_b-1]);
		
			printf("\n%d : ",ndex_a);
			for(i=0; i<ndex_a; i++)//for(; ndex_c>0; (ndex_c)--)
				printf("%d ",a[i]);//ndex_c-1]);
		}
		else
		{
			printf("\n%d : ",ndex_a);
			for(i=0; i<ndex_a; i++)//for(; ndex_c>0; (ndex_c)--)
				printf("%d ",a[i]);//ndex_c-1]);
			printf("\n%d : ",ndex_b);
			for(i=0; i<ndex_b; i++)//for(; ndex_b>0; (ndex_b)--)
				printf("%d ",b[i]);//ndex_b-1]);
		
		}
		
	}

	printf("\n");
}
int main()
{
	int index_a=0, index_b=0, index_c=0,n;
	int a[50] ={0}; int b[50] = {0}; int c[50] = {0};
	A = a; B = b; C = c;
	printf("Enter the no. of disks in peg A.."); scanf("%d",&n);
	for(; index_a<n; ++index_a)
	{
		a[index_a] = n-index_a;
	}
	showStatus(&index_a, &index_b, &index_c, a, b, c);
	move(n, a, &index_a, c, &index_c, b, &index_b);
	return 0;
}
