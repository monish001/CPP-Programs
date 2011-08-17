#include<iostream>
using namespace std;
//Question 4. Implement optimal binary search tree using dynamic programming.
/*Test case:
	int n = 5;
	float p[]={.05, .10, .10, .15, .2}, q[]={.05, .05, .05, .05, .1, .1};
	viewTree(OptimalBST(n, p, q));
Output:
	k3is the root
	k1 is the left child of k3
	d0 is the left child of k1
	k2 is the right child of k1
	d1 is the left child of k2
	d2 is the right child of k2
	k4 is the right child of k3
	d3 is the left child of k4
	k5 is the right child of k4
	d4 is the left child of k5
	d5 is the right child of k5
	Cost:2.55
	---------FINAL root[i][j]--
	0 1 1 2 3 3
	0 0 2 3 3 4
	0 0 0 3 4 4
	0 0 0 0 4 4
	0 0 0 0 0 5
	0 0 0 0 0 0
	Press any key to exit
Analysis:
        k3
      /    \
    k1      k4
   /  \    /  \
  d0  k2  d3  k5
     / \     /  \
    d1  d2  d4  d5

*/
template<class T>
T** make_2Dmat(int m,int n){
	T** mat=new T*[m];
	for(int j=0;j<m;j++){
		mat[j]=new T[n];
	}
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			mat[i][j]=0;
	return mat;
}
void child(int **root, int i, int j,int r,char dir[]){
	if(j<i){
		cout<<"\nd"<<j<<" is the "<<dir<<" child of k"<<r;
		return;
	}
    int r_new=root[i][j];
	cout<<"\nk"<<r_new<<" is the "<<dir<<" child of k"<<r;
	child(root,i,r_new-1,r_new,"left");
	child(root,r_new+1,j,r_new,"right");

}

void make_tree(int **root, int n){
 int r=root[1][n];
 cout<<"\nk"<<r<<"is the root";
 child(root,1,r-1,r,"left");
 child(root,r+1,n,r,"right");

}
float OptimalBST(int n, float p[], float q[], int** root){
	float e[n+2][n+1], w[n+2][n+1];
	memset(e, 0, (n+1)*(n+2)*sizeof(float));
	memset(w, 0, (n+1)*(n+2)*sizeof(float));
	for(int i=1; i<=n+1; i++){
		e[i][i-1] = q[i-1];
		w[i][i-1] = q[i-1];
	}
	for(int iter=1, i_max; iter<=n; iter++){
		i_max = n+1-iter;
		for(int i=1, j; i<=i_max; i++){
			j=i+iter-1;
			e[i][j] = 100;
			//root[i][j]=i;
			w[i][j] = w[i][j-1] + p[j] + q[j];
			

			float t;
			for(int r=i; r<=j; r++){
				t = w[i][j] + e[i][r-1] + e[r+1][j];
				if(t<e[i][j]){
					e[i][j] = t;
					root[i][j]=r;
				}
			}
		}
	}
	make_tree(root, n);
	return e[1][n];
}

int main(){
	int n = 5, data[] = {'a', 'f', 'k', 'n', 'u'};
	float p[]={.05, .10, .10, .15, .2}, q[]={.05, .05, .05, .05, .1, .1};
	//float q[]={.05, .10, .10, .15, .17, .03}, p[]={.05, .05, .05, .15, .1};
	int **root = make_2Dmat<int>(n+2, n+1);
	//int root[n+2][n+1];
	cout<<"\nCost:"<<OptimalBST(n, p, q, (int**)root);
	cout<< "\n---------FINAL root[i][j]---------------------\n";
	for(int i=1; i<=n+1; i++){
		for(int j=0; j<=n; j++)
			cout<<root[i][j]<<" ";
		cout<<"\n";
	}
	delete []root;
	cout<<"Press any key to exit";
	getchar();
	return 0;
}
