#include<cmath>
#include<iostream>
using namespace std;

//Question 1. Implement operations of a complete binary search tree with the following functionalities with each operations as a separate function:
/*
Test case:
	completeBST bsttree;
	int a[4]={12,23,5,8};
    for(int i=0; i<4; i++)
        bsttree.insert(a[i]);
    cout<<"No. of external nodes="<<bsttree.noofexternalnodes()<<"\n";
    bsttree.breadthWiseTraverse();
    int index = bsttree.search(8);
    cout<<"Index of 8 is "<<index<<"\n";
    cout<<"Predecessor of 8 in tree:"<<bsttree.predecessor(index)<<"\n";
    index = bsttree.search(12);
    cout<<"Index of 12 is "<<index<<"\n";
    cout<<"Predecessor of 12 in tree:"<<bsttree.predecessor(index)<<"\n";
    bsttree.insert(30);
    bsttree.breadthWiseTraverse();
    bsttree.insert(20);
    bsttree.breadthWiseTraverse();
    cout<<"Size of tree is "<<bsttree.size()<<"\n";
    cout<<"Left child value of 12: "<<bsttree.leftchild(12)<<"\n";
    cout<<"Right child value of 12: "<<bsttree.rightchild(12)<<"\n";
    cout<<"Height of tree is: "<<bsttree.height()<<"\n";
    cout<<"Sibling of 5 is: "<<bsttree.sibling(5)<<"\n";
    cout<<"Sibling of 23 is: "<<bsttree.sibling(23)<<"\n";
    cout<<"Sibling of 8 is: "<<bsttree.sibling(8)<<"\n";    
    bsttree.insert(2);
    bsttree.breadthWiseTraverse();
    bsttree.insert(1);
    bsttree.breadthWiseTraverse();
    cout<<"Sibling of 1 is: "<<bsttree.sibling(1)<<"\n";
    bsttree.delete1(5);//delete node having no child//argument is index
    bsttree.breadthWiseTraverse();
    bsttree.insert(9);
    bsttree.breadthWiseTraverse();
    bsttree.delete1(4);//delete node having only right child
    cout<<"After deletion of index 4:";
    bsttree.breadthWiseTraverse();
    bsttree.delete1(3);//delete node having only left child
    cout<<"After deletion of index 3:";
    bsttree.breadthWiseTraverse();
    bsttree.delete1(0);//delete node having only left child
    cout<<"After deletion of index 0:";
    bsttree.breadthWiseTraverse();
Output:
	Predecessor of 8 in tree:5
	Index of 12 is 0
	Predecessor of 12 in tree:8
	Breadth first traversal sequence: 0:12 1:5 2:23 3:-1 4:8 5:-1 6:30
	Breadth first traversal sequence: 0:12 1:5 2:23 3:-1 4:8 5:20 6:30
	Size of tree is 7
	Left child value of 12: 5
	Right child value of 12: 23
	Height of tree is: 3
	Sibling of 5 is: 23
	Sibling of 23 is: 5
	Sibling of 8 is: -1
	Breadth first traversal sequence: 0:12 1:5 2:23 3:2 4:8 5:20 6:30
	Breadth first traversal sequence: 0:12 1:5 2:23 3:2 4:8 5:20 6:30 7:1
	Sibling of 1 is: -1
	Breadth first traversal sequence: 0:12 1:5 2:23 3:2 4:8 5:-1 6:30 7:1
	Breadth first traversal sequence: 0:12 1:5 2:23 3:2 4:8 5:-1 6:30 7:1 8:-1 9:-1	10:9
	After deletion of index 4:Breadth first traversal sequence: 0:12 1:5 2:23 3:2 4:9 5:-1 6:30 7:1 8:-1 9:-1 10:-1
	After deletion of index 3:Breadth first traversal sequence: 0:12 1:5 2:23 3:1 4:9 5:-1 6:30 7:-1 8:-1 9:-1 10:-1
	After deletion of index 0:Breadth first traversal sequence: 0:9 1:5 2:23 3:1 4:-1 5:-1 6:30 7:-1 8:-1 9:-1 10:-1
*/
typedef int T;
class array{
	T *ar;
	unsigned int sizeIndex;//index to the total number of items that can be stored into by-now-allocated memory
	int topIndex;//index to the item at the end/top
	public:
	array():ar(new T[2]),topIndex(-1), sizeIndex(1){}
	array(int N):topIndex(N-1),sizeIndex(N-1),ar(new T[N]){}
	~array(){
             delete[] ar;
    };
	int count(){
		return topIndex+1;
	}
	bool push(T item){//to increase the arraysize;
		if(topIndex == sizeIndex){
			sizeIndex = (sizeIndex+1)*2-1;
			T *temp = new T[sizeIndex+1];
			for(int i=0; i<=topIndex; i++)				temp[i]=ar[i];//copy count-1 elements
			delete[] ar;
			ar=temp;
		}
		ar[++topIndex]=item;
	}
	//places (t)item at (int)index of variable array
	bool push(int index, T item){//to increase the arraysize;
		if(topIndex==-1){
			this->push(item);
			return true;
		}else if(index<=topIndex){
			*(ar+index)=item;
			return true;
		}
		for(;topIndex<index-1;)
			this->push(-1);
		this->push(item);
		return true;
	}
	T& operator[](int index){//for reading or writing into the array
		if(index<0){
			cout<<"ERROR: Array Underflow\nProgram is terminating. Press any key.\n";
			fflush(stdin);
			getchar();
			exit(0);
		}
		if(index>topIndex){
			cout<<"ERROR: Array Overflow with index="<<index<<"\nProgram is terminating. Press any key.\n";
			fflush(stdin);
			getchar();
			exit(0);
		}
		return ar[index];
	}
};

class completeBST{
	array tree;
	double log2(double a){
		return log(a)/log(2);
	}
    void map(int par_ind, int chi_ind){
		if( chi_ind>tree.count()-1 || tree[chi_ind]==-1 )//this would never be true (see passed args in delete())
			return;
		tree[par_ind]=tree[chi_ind];
		tree[chi_ind]=-1;
		map(2*par_ind+1, 2*chi_ind+1);
		map(2*par_ind+2, 2*chi_ind+2);
    }
	public:
	~completeBST(){}
	int search(T p){
		int index, count=tree.count();
		for(index=0; index<count && tree[index] != p;){
			if(p>tree[index])
				index= index*2+2;
			else
				index= index*2+1;
		}
		if(index == count)//not found
			return -1;
		return index;
	}
	//Question 1.i size() which returns total number of nodes in the tree.
	int size(){//returns number of nodes
		return tree.count();
	}

	//Question 1.ii leftchild(p) returns left child of p
	T leftchild(T p){
		int index = search(p);
		index = 2*index+1;
		if(index <= tree.count()-1)
			return tree[index];
		else
			return -1;
	}
	//Question 1.iii height() returns the height of the tree
	int height(){
		return ((int)log2(tree.count()))+1;
	}

	//Question 1.iv rightchild(p) returns the right child of a node
	T rightchild(T p){
		int index = search(p);
		index = 2*index+2;
		if(index <= tree.count()-1)
			return tree[index];
		else
			return -1;
	}

	//Question 1.v sibling(p) returns the sibling of a node
	T sibling(T p){
		int index=search(p);
		if(index%2==0)
			return tree[index-1];
		else if(index+1 <= tree.count()-1)
			return tree[index+1];
		else
			return -1;
	}

	//Question 1.vi noofexternalnodes() returns the total number of external nodes in a tree
	int noofexternalnodes(){
		return (tree.count()+1)/2;
	}

	//Question 1.vii delete1(p){ deletes the element p and preserves the binary search tree property
	void delete1(int index){
		int topIndex = tree.count()-1;
		if(2*index+1 > topIndex)//no children present
			tree[index]=-1;
		else if(2*index+1==topIndex){//only left node present
			if(tree[topIndex]==-1)
				tree[index]=-1;
			else
				map(index/*parent*/, topIndex/*child*/);
		}else{
			int left = tree[2*index+1];
			int right = tree[2*index+2];
			if(right!= -1 && left != -1){//both child present
				int new_ind = 2*index+1;
				while(2*new_ind+2<=topIndex && tree[2*new_ind+2] != -1)
					new_ind = 2*new_ind+2;
				tree[index]=tree[new_ind];
				tree[new_ind]=-1;
			}else if(right != -1)//only right child present
				map(index, 2*index+2);
			else//only left child present
				map(index, 2*index+1);
		}
	}

	//Question 1.viii insert(p) inserts the element p at the appropriate position
	void insert(T p){
		int i=0;
		while( i<=(tree.count()-1) && tree[i] != -1){//while i!=topIndex AND
			if(p>tree[i])
				i=2*i+2;
			else
				i=2*i+1;
		}
		if(i> tree.count()-1){
			tree.push(i, p);
        }
		else{
			tree[i]=p;
		}
	}

	//Question 1.ix predecessor(p) returns the predecessor of value at index
	T predecessor(int index){
		int topIndex = tree.count()-1;
		if(index<0 || index>topIndex)//index out of bound
			return -1;
		if(2*index+1 <= topIndex && tree[2*index+1]!=-1){//return largest value in left child subtree
			int new_ind = 2*index+1;
			while(2*new_ind+2<=topIndex && tree[2*new_ind+2] != -1){
				new_ind=2*new_ind+2;
			}
			return tree[new_ind];
		}
		if((index-1)/2 >= 0)//return root value
			return tree[(index-1)/2];
		else
			return -1;
	}
	void breadthWiseTraverse(){
		int topIndex = tree.count()-1;
        cout<<"Breadth first traversal sequence: ";
		for(int i=0; i<=topIndex; i++)
			cout<<i<<":"<<tree[i]<<" ";
		cout<<"\n";
	}
};