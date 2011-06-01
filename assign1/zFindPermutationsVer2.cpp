#include<iostream>
using namespace std;

/*Question 7. Given two graphs, find out whether one graph is isomorphic to another or not.*/

/*
bool areSame(const int &A[][], const int &B[][], const int size){
	for i<-0 to size-1
		for j<-0 to size-1
			if A[i][j] != B[i][j]
				return false
	return true
}*/
bool areSame(int** A, const int** B, const int size){
	for(int i=0; i<=size-1; i++)
		for(int j=0; j<=size-1; j++)
			if(A[i][j] != B[i][j])
				return false;
	return true;
}
/*
bool isIsomorphic(int A[][], int startIndex, const int na, const int &B[][], const int &nb){
	//returns true if graphs are isomorphic else false
	//check sizes
	if na != nb
		return false
	//finds each permutation of A and matches that with B
	if startIndex == na-1
		for i<-0 to na-1
			for j<-0 to na-1
				print a[i][j]
				print space
			print newline
		return areSame(A, B, na)
	for i<-0 to n-1
		swap col[0] with col[i] of A
		swap row[0] with row[i] of A
		if isIsomorphic(A, startIndex+1, na) == true
			return true
	return false
}*/
void swap(int &a, int &b){
static int t=a;	a=b;	b=t;
}
bool isIsomorphic(int** AR, int startIndex, const int na, const int** B, const int &nb){
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
/*findPermutations(array a, int startIndex, int size)
	if startIndex == size-1
		for i<-0 to size-1//print sequence in array a
			print a[i]
			print space
		print newline
		return
	for i<-0 to n-1
		swap a[0] with a[i]
		findPermutations(a, startIndex+1, size)
Test case:
	int arr[3]={1,2,3};
	findPermutations(arr, 0, 3);
Output:
	1 2 3
	1 3 2
	2 1 3
	2 3 1
	3 1 2
	3 2 1
*/
void findPermutations(int *ar, int startIndex, int size){
	if(startIndex == size-1){
		for(int i=0; i<size; i++)//print sequence in array ar
			cout<<ar[i]<<" ";
		cout<<"\n";
		return;
	}
	int *a = new int[size];
	for(int i=0; i<size; i++)
		a[i]=ar[i];
	int temp;
	for(int i=startIndex; i<size; i++){
		//swap a[0] with a[i]
		temp=a[startIndex];
		a[startIndex]=a[i];
		a[i]=temp;
		findPermutations(a, startIndex+1, size);
	}
	delete[] a;
}
int main(){
	getchar();
	return 0;
}