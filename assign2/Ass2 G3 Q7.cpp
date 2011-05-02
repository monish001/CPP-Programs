#include<iostream>
using namespace std;

void swap(int &a, int &b){
static int t; t=a;	a=b;	b=t;
}
bool areSame(int** A, int** B, int size){
	for(int i=0; i<=size-1; i++)
		for(int j=0; j<=size-1; j++)
			if(A[i][j] != B[i][j])
				return false;
	return true;
}
/*Question 7. Given two graphs, find out whether one graph is isomorphic to another or not.*/
/*
Test case:
	int**a=new int*[4];
	int**b=new int*[4];
	for(int i=0; i<4; i++){
		a[i]=new int[4];
		b[i]=new int[4];
	}
	a[0][0]=0;	a[0][1]=0;	a[0][2]=1;	a[0][3]=1;
	a[1][0]=0;	a[1][1]=0;	a[1][2]=1;	a[1][3]=1;
	a[2][0]=1;	a[2][1]=1;	a[2][2]=0;	a[2][3]=0;
	a[3][0]=1;	a[3][1]=1;	a[3][2]=0;	a[3][3]=0;
	b[0][0]=0;	b[0][1]=1;	b[0][2]=0;	b[0][3]=1;
	b[1][0]=1;	b[1][1]=0;	b[1][2]=1;	b[1][3]=0;
	b[2][0]=0;	b[2][1]=1;	b[2][2]=0;	b[2][3]=1;
	b[3][0]=1;	b[3][1]=0;	b[3][2]=1;	b[3][3]=0;
	cout<<isIsomorphic(a, 0, 4, b, 4);
Output:
	1
}*/
bool isIsomorphic(int** AR, int startIndex, int na, int** B, int nb){
	//returns true if graphs are isomorphic else false
	//check sizes
	if(na != nb)
		return false;
	//return areSame() if last column
	if(startIndex == na-1){
		for(int i=0; i<na; i++){
			for(int j=0; j<na; j++)
				cout<<AR[i][j]<<" ";
			cout<<"\n";
		}
		cout<<"--------\n";
		return areSame(AR, B, na);
	}
	//create copy of 2-D array AR
	int**A=new int*[na];
	for(int i=0; i<na; i++){
		A[i]=new int[na];
		for(int j=0; j<na; j++){
			A[i][j]=AR[i][j];
		}
	}
	//finds each permutation of A and matches that with B
	for(int i=0; i<na; i++){
		if(i != 0){
			for(int j=0; j<na; j++)//swap col[0] with col[i] of A
				swap(A[j][i], A[j][0]);
			for(int j=0; j<na; j++)//swap row[0] with row[i] of A
				swap(A[i][j], A[0][j]);
		}
		if(isIsomorphic(A, startIndex+1, na, B, nb) == true){
			for(int i=na-1; i>=0; i--)
				delete[] A[i];
			return true;
		}
	}
	for(int i=na-1; i>=0; i--)
		delete[] A[i];
	return false;
}