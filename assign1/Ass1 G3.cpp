/*
ALGORITHM ANALYSIS & DESIGN(CS007)
ASSIGNMENT 1
4 FEB 2011

SUBMITTED BY:
MONISH GUPTA
100803060
3RD YEAR, CSE BE.
*/

#include<iostream>
using namespace std;

//Question 1. Implement a doubly link list with the following functionalities with each operation as a seperate function:
class node{
	public:
	int data;
	node* prev;
	node* next;
	node():data(-1), prev(NULL), next(NULL){}
};

/*Question 1.i Creation of a doubly link list with single node
Test case:
	node* node1 = createFirst(23);
	if(node1==NULL)
		cout<<"Error";
	else
		cout<<"done.."<<node1->data;
Output:
	done..23
*/
node* createFirst(int datum){
//ARGUMENTS:
	//int datum: data for the new node
//PROCEDURE:
	//creates a new doubly link list node
	//sets its data to passed argument
	//returns address of new node
	node* ptr = new node;
	if(ptr != NULL)
		ptr->data = datum;
	return ptr;
}

/*Question 1.ii.a Insertion in a doubly link list
Test case:
	node *start = new node;
	start->data = 1;
	if(insertAtStart(5, start))
		cout<<start->data;
Output:
	5
Test case:
	node *start = NULL;
	if(insertAtStart(5, start) && insertAtStart(15, start))
		cout<<start->data<<"\n"
		<<start->next->data;
Output:
	15
	5
*/
bool insertAtStart(int datum, node* &node1){
//ARGUMENTS:
	//int datum: data for the new node.
	//node* &node1: reference of pointer to start of the doubly link list.
//PROCEDURE:
	//creates a new doubly link list node. If failed, it returns false.
	//sets its data to passed argument.
	//sets node1 reference to the new node
	//returns true to indicate success.
	node* ptr = new node;
	if(ptr == NULL)
		return false;
	ptr->data = datum;
	ptr->next = node1;

	if(node1!=NULL){
		node* last = node1->prev;
		ptr->prev = last;
		if(last!=NULL)
	        last->next=ptr;
		node1->prev = ptr;
	}
	node1 = ptr;
	return true;
}

/*Question 1.ii.b Insertion in a doubly link list at END
Test case:
	node *start = new node;
	start->data = 1;
	if(insertAtEnd(5, start))
		cout<<start->next->data;
Output:
	5
Test case:
	node *start = NULL;
	if(insertAtEnd(5, start) && insertAtEnd(15, start))
		cout<<start->data<<"\n"
		<<start->next->data;
Output:
	15
	5
*/
bool insertAtEnd(int datum, node* &node1){
//ARGUMENTS:
	//int datum: data for the new node.
	//node* &node1: reference of pointer to start of the doubly link list.
//PROCEDURE:
	//creates a new doubly link list node. If failed, it returns false.
	//sets new node's data to passed argument.
	//sets node1 = new node
	//returns true to indicate success.
	node* ptr = new node;
	if(ptr == NULL)
		return false;
	ptr->data = datum;
	
	if(node1 == NULL){
		node1 = ptr;
		return true;
	}
	
	node* last = node1;
	while(last->next != NULL){
		last = last->next;
	}
	last->next = ptr;
	ptr->prev = last;
	return true;
}

/*Question 1.ii.c Inserting in a Doubly link list before the first occurence of the specified element in the list
Test case:
	node *start = new node;
	start->data = 1;
	if(!insertPreX(5, start, 34))
		cout<<"Not Inserted. (as expected)";
Output:
	Not Inserted. (as expected)
Test case:
	node *start = createFirst(5);
	if(insertPreX(1, start, 5)){
		node* ptr = start;
		for(; ptr != NULL; ptr=ptr->next)
			cout<<ptr->data<<" ";
	}else cout<<"err\n";
Output:
	1 5
Test case:
	node *start = createFirst(5);
	if(insertAtEnd(15, start)){
		if(insertPreX(10, start, 15)){
			node* ptr = start;
			for(; ptr != NULL; ptr=ptr->next)
				cout<<ptr->data<<" ";
		}else cout<<"err1 ";
	}else cout<<"err2 ";
Output:
	5 10 15 
*/
bool insertPreX(int datum, node* &node1, int x){
//ARGUMENTS:
	//int datum: data for the new node.
	//node* &node1: reference of pointer to start of the doubly link list.
	//int x: insert before first occurence of x
//PROCEDURE:
	//if node1 == NULL, returns false.
	//finds appropriate location for new node. If location not found, returns false.
	//creates a new doubly link list node. If failed, it returns false.
	//sets new node's data to passed argument.
	//returns true to indicate success.
	if(node1 == NULL)
		return false;
	if(x == node1->data){//insert at start
		return insertAtStart(datum, node1);
	}
	node* find = node1->next;
	while(find!=NULL){
		if(find->data == x)
			break;
		find = find->next;
	}
	if(find == NULL)//if data not found
		return false;
	node* ptr = new node;
	if(ptr == NULL)
		return false;
	ptr->data = datum;

	ptr->next = find;
	ptr->prev = find->prev;
	if(find->prev != NULL)
		(find->prev)->next = ptr;
	find->prev = ptr;
	return true;
}

/*Question 1.ii.d Inserting in a Doubly link list after the first occurence of the specified element in the list
//Test case:
	node *start = createFirst(1);
	if(!insertPostX(5, start, 34))
		cout<<"Not Inserted. (as expected)";
//Output:
//	Not Inserted. (as expected)
//Test case:
	node *start = createFirst(5);
	if(insertPostX(1, start, 5)){
		node* ptr = start;
		for(; ptr != NULL; ptr=ptr->next)
			cout<<ptr->data<<" ";
	}else cout<<"err\n";
//Output:
//	5 1 
//Test case:
	node *start = createFirst(5);
	if(insertAtEnd(15, start)){
		if(insertPostX(10, start, 5)){
			node* ptr = start;
			for(; ptr != NULL; ptr=ptr->next)
				cout<<ptr->data<<" ";
		}else cout<<"err1 ";
	}else cout<<"err2 ";
//Output:
//	5 10 15
*/
bool insertPostX(int datum, node* &node1, int x){
//ARGUMENTS:
	//int datum: data for the new node.
	//node* &node1: reference of pointer to start of the doubly link list.
	//int x: insert after first occurence of x
//PROCEDURE:
	//if node1 == NULL, returns false.
	//finds appropriate location for new node. If location not found, returns false.
	//creates a new doubly link list node. If failed, it returns false.
	//sets new node's data to passed argument.
	//returns true to indicate success.
	if(node1 == NULL)//no x could be found
		return false;
	node* find = node1;
	while(find!=NULL){
		if(find->data == x)
			break;
		find = find->next;
	}
	if(find == NULL)//if data not found
		return false;
	node* ptr = new node;
	if(ptr == NULL)
		return false;
	ptr->data = datum;

	ptr->prev = find;
	ptr->next = find->next;
	find->next = ptr;
	if(ptr->next != NULL)
		(ptr->next)->prev = ptr;
	return true;
}

//Question 1.iii.a Deletion in a doubly link list:
//Question 1.iii.a First element of the list, should check whether the list is empty
bool deleteFirst(node* &start){
cout<<"here\n";
	if(start==NULL)//list is empty
		return false;
	node* ptr = start;
	start = start->next;
	start->prev=NULL;
	delete ptr;
	return true;
}

//Question 1.iii.b Last element of the list, should check whether the list is empty
bool deleteLast(node* &start){
	if(start==NULL)//list is empty
		return false;
	if(start->next==NULL){//list has only one element
		delete start;
		start = NULL;
		return true;
	}
	node* last;
	for(last=start; last->next!=NULL; last=last->next)
		;
	(last->prev)->next = NULL;
	delete last;
	return true;
}

//Question 1.iii.c Specified element in the list, should check whether the list is empty
bool deleteX(node* &start, int x){
	if(start==NULL)//list is empty
		return false;
	if(start->data==x){//delete first element
		return deleteFirst(start);
	}
	node* find;
	for(find = start; find != NULL; find = find->next){
		if(find->data == x)
			break;
	}
	if(find==NULL)//x not found
		return false;
	if(find->next == NULL)//if last node
		return deleteLast(start);
	(find->prev)->next = find->next;
	(find->next)->prev = find->prev;
	delete find;
	return true;
}

//Question 1.iv Merging two linked lists
bool mergelist(node *&link1,node *link2){
//appends list 2 at the end of list 1
//returns true if successful
	if(link1 == NULL){
		link1 = link2;
		return true;
	}
    node *last;
	for(last = link1; last->next!=NULL; last=last->next)
		;
	last->next = link2;
	return true;
}

//Question 1.v Splitting a linked list in two linked lists
node* splitlist(node* &start, int x){
//splits list just before first occurence of x
//returns pointer to node having data=x
	if(start==NULL)//if list empty
		return NULL;
	if(start->data == x){
		node* ptr = start;
		start = NULL;
		return ptr;
	}
	node* find;
	for(find = start; find!=NULL; find=find->next){
		if(find->data==x)
			break;
	}
	if(find==NULL)
		return NULL;
	(find->prev)->next = NULL;
	return find;
}

//Question 1.vi Giving the size of a linked list
int size(node* start){
//returns number of nodes in the list.
	if(start == NULL)
		return 0;
	node* ptr = start;
	int i;
	for(i=0; ptr!=NULL;i++, ptr=ptr->next)
		;
	return i;
}

/*Question 2 Write a program to find the maximum and minimum of a given set of numbers.

Test case:
	int a[5] = {1,2,3,4,5};
	int min = -1, max = -1;
	minAndMax(a, 5, max, min);
	cout<<"Max:"<<max<<"\n";
	cout<<"Min:"<<min<<"\n";
Output:
	Max:5
	Min:1

Test case:
	int a[5] = {5,4,3,2,1};
	int min = -1, max = -1;
	minAndMax(a, 5, max, min);
	cout<<"Max:"<<max<<"\n";
	cout<<"Min:"<<min<<"\n";
Output:
	Max:5
	Min:1

Test case:
	int a[5] = {1,2,5,4,3};
	int min = -1, max = -1;
	minAndMax(a, 5, max, min);
	cout<<"Max:"<<max<<"\n";
	cout<<"Min:"<<min<<"\n";
Output:
	Max:5
	Min:1
*/
void minAndMax(const int *A, const int &N, int &max, int &min){
	min = max = A[0];
	for(int i=2; i<N; i++){
		if(max < A[i])
			max = A[i];
		else if(min > A[i])
			min = A[i];
	}
}

/*Question 3 Finding the maximum and next maximum of a given set of numbers

Test case:
	int a[3] = {5,2,2};
	int max1 = -1, max2 = -1;
	max1AndMax2(a, 3, max1, max2);
	cout<<"Max1:"<<max1<<"\n";
	cout<<"Max2:"<<max2<<"\n";
Output:
	Max1:5
	Max2:2

Test case:
	int a[3] = {2,2,5};
	int max1 = -1, max2 = -1;
	max1AndMax2(a, 3, max1, max2);
	cout<<"Max1:"<<max1<<"\n";
	cout<<"Max2:"<<max2<<"\n";
Output:
	Max1:5
	Max2:2

Test case:
	int a[3] = {2,5,2};
	int max1 = -1, max2 = -1;
	max1AndMax2(a, 3, max1, max2);
	cout<<"Max1:"<<max1<<"\n";
	cout<<"Max2:"<<max2<<"\n";
Output:
	Max1:5
	Max2:2

*/
void max1AndMax2(const int *A, const int &N, int &max1, int &max2){
	if(A[0] > A[1])
		max1 = A[0], max2 = A[1];
	else
		max1 = A[1], max2 = A[0];
	for(int i=2; i<N; i++){
		if(max1 < A[i]){
			max2 = max1;
            max1 = A[i];
		}
		else if(max2 < A[i])
			max2 = A[i];
	}
}

/*Question 4. Solve Josephus permutation problem which is defined as: Suppose n people are arranged in circle & we are given a positive integer m <= n. Beginning with a designed first person, we proceed around the circle removing m th person. After each person is removed, counting continues around the circle that remains. This continues until all n people have been removed. The order in which the people are removed from the circle defines (n,m) Josephus permutation.
Test case:
	josephus(7,3);
Output:
	3 6 2 7 5 1 4
*/
class nodes{
//Complexity: O(mn), Only last survivor can be computed in O(n) not the list.
	public:
		int data;
		nodes* link;
};
void josephus(int n, int  m){
//STEP1. create cirular link list with n nodes.
	nodes *ptr=NULL, *start=NULL, *end=NULL;
	cout<<"Initial sequence: ";
	for(int i=1; i<=n; i++){
		ptr=new nodes;//get new node dynamically
		ptr->data=i;//new node's data is value of i
		if(i==1){//if first node
			start=ptr;//first node is start node also.
			ptr->link=ptr;//the first node's link points to itself.
			end=ptr;//first node is end node also.
		} else{//else add the new node at end
			ptr->link=start;//new node's link points start.
			end->link=ptr;//the earlier end node's link should point to new node, ptr.
			end=ptr;//now update the end node
		}
		cout<<i<<" ";
	}//STEP 1 complete.
/*//STEP 2 test the circular link list.
	ptr=start;
	while(ptr!=end){
		cout<<ptr->data;
		ptr=ptr->link;
	}*/
//STEP 3 Retrieve josephus sequence
	cout<<"\nJosephus Sequence: ";
	nodes *temp=NULL;
	ptr=start;
	int i=1;
	while(ptr->link != ptr){//untill we are not left with 1 node.
		if(i==m){
			temp = ptr->link;
			cout<<ptr->data<<" ";
			ptr->data = temp->data;
			ptr->link=temp->link;
			delete temp;
			i=1;
		}else{
			ptr = ptr->link;
			i++;
      }
	}
	cout<<ptr->data;
	delete ptr;
}

/*Question 5 Write an algorithm for checking that whether a given word is an anagram of another word. The word should have same length and same frequency of each letter occuring in the original word.
Test case:
	cout<<isAnagram("qet", "qte");
Output:
	1

Test case:
	cout<<isAnagram("abc cba", "aabbcc");
Output:
	0
*/
bool isAnagram(char* word1, char *word2){
	int len1=-1, len2=-1;
	len1 = strlen(word1);
	len2 = strlen(word2);
	if(len1 != len2)
		return 0;
	int count[256]={0};
	for(int i=0; i<len1; i++){
		count[word1[i]]++;
		count[word2[i]]--;
	}
	for(int i=0; i<256; i++){
		if(count[i]!= 0)
			return 0;
	}
	return 1;
}

/*Question 6 Suppose that each row of an nXn array A consists of 1's and 0's such that in any row i of A, all the 1's come before any 0's in that row. Suppose further that the number of 1's in the row i is less than or equal to the number in row i+1, for i=0,1,2...n-2. Assuming A is already in memory, describe a method running in O(n) time for counting the number of 1's in the array.
//Test case:
	int z[3][3]={1,0,0,1,0,0,1,1,0};
	cout<<"\n4 = "<<count1s((int**)z,3);
//Output:
//	4
//Test case:
	int b[5][5]={0,0,0,0,0, 1,0,0,0,0, 1,1,1,0,0, 1,1,1,0,0, 1,1,1,1,1};
	cout<<"\n12 = "<<count1s((int**)b,5);
//Output:
//	12
//Test case:
	int c[5][5]={0,0,0,0,0, 1,0,0,0,0, 1,1,1,0,0, 1,1,1,1,1, 1,1,1,1,1};
	cout<<"\n14 = "<<count1s((int**)c,5);
//Output:
//	14
//Test case:
	int d[4][4]={0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
	cout<<"\n0 = "<<count1s((int**)d,4);
//Output:
//	0	
//Test case:
	int e[4][4]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
	cout<<"\n16 = "<<count1s((int**)e,4);
//Output:
//	16
*/
int count1s(int **b, int n){
    //cout<<"\n"<<b<<" "<<*b;
	int *a; a = (int*)b;
	int i=0, count=0;
	while(i<n*n){
		//cout<<"in count1s "<<i<<"\n";
		if((*(a+i))==0){
			i+=n;
		} else{//if a[i] is 1
			count += n - i/n;//i/n is rowIndex
			if(i%n == n-1)//if column,i.e.(i%n) of i is last column (n-1), then break the loop
				break;
			i++;
		}
	}
	return count;
}

/*Question 7 An array A contains n-1 unique integers in the range [0,n-1] that is there is one number from the range [0,n] that is not in A. Design an O(n) time algorithm for finding that number. You are allowed to use only O(1) additional space besides the array A itself.
//Test case:
	int a[9-1] = {8,7,6,9,1,4,3,5};
    cout<<"\n"<<findMissingInt(a, 9);
//Output:
//	2
*/
int findMissingInt(int *a,int n){
	int num=n*(n+1)/2;//sum of first n natural numbers.
	for(int i=0; i < n-1; i++)
		num -= a[i];
	return num;
}
int main(){
    getchar();
    return 0;
}
