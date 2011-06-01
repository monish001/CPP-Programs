#include<iostream>
using namespace std;

/*Question 7. Given two graphs, find out whether one graph is isomorphic to another or not.
bool isIsomorphic(A, na, B, nb){//returns true if graphs are isomorphic else false
	
}
	
findPermutations(array a, int startIndex=0, int EndIndex=n-1, int size)
	if EndIndex-startIndex == 0
		for i<-0 to size-1//print sequence in array a
			print a[i]
			print space
		print newline
	for i<-0 to n-1
		swap a[0] with a[i]
		findPermutations(a, 1, n-1, size)
*/
void findPermutations(int *ar, int startIndex, int size){
	int *a = new int[size];
	for(int i=0; i<size; i++)
		a[i]=ar[i];
	cout<<a[startIndex]<<"\n";
	if(startIndex == size-1){
		for(int i=0; i<size; i++)//print sequence in array a
			cout<<a[i]<<" ";
		cout<<"\n";
		delete[] a;
		return;
	}
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
	int arr[3]={1,2,3};
	findPermutations(arr, 0, 3);
	getchar();
	return 0;
}