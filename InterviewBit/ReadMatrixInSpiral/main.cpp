#include<iostream>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include <climits>
using namespace std;

#define ll long long
#define pii pair<int,int>

vector<int> spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	// DO STUFF HERE AND POPULATE result
    int m = A.size(), n = A[0].size();
	// for index = 0 to (max(m,n) - 1)/2.
    for(int index=0; index <= (min(m,n))/2 - 1; index++)
    {
    	// read top left corner
    	//cout<<A[index][index]<<"\t";
    	result.push_back(A[index][index]);

    	// read top, left to right
    	for(int col=index+1; col<n-index-1; col++){
            //cout<<A[index][col]<<"\t";
            result.push_back(A[index][col]);
    	}

    	// read right top corner
    	//cout<<A[index][n-index-1]<<"\t";
    	result.push_back(A[index][n-index-1]);

    	// read right, top to bottom
    	for(int row = index+1; row<m-index-1; row++){
            //cout<<A[row][n-index-1]<<"\t";
            result.push_back(A[row][n-index-1]);
    	}

    	// read right bottom corner
    	//cout<<A[m-index-1][n-index-1]<<"\t";
    	result.push_back(A[m-index-1][n-index-1]);

    	// read bottom, right to left
    	for(int col=n-index-2; col>index; col--){
            //cout<<A[m-index-1][col]<<"\t";
            result.push_back(A[m-index-1][col]);
    	}

    	// read bottom left corner
    	//cout<<A[m-index-1][index]<<"\t";
    	result.push_back(A[m-index-1][index]);

    	// read left, bottom to top
    	for(int row=m-index-2; row>index; row--){
            //cout<<A[row][index]<<"\t";
            result.push_back(A[row][index]);
    	}

    	//cout<<endl;
    }
    int midRow = m/2, midCol = n/2;
    if(m > n && n%2 == 1){
        int initRow = (n-1)/2;
        for(int row=initRow; row<m-initRow;row++){
            //cout<<A[row][midCol]<<"\t";
            result.push_back(A[row][midCol]);
        }
    }else if(n > m && m%2 == 1){
        int initCol = (m-1)/2;
        for(int col = initCol; col<n-initCol; col++){
            //cout<<A[midRow][col]<<"\t";
            result.push_back(A[midRow][col]);
        }
    }else if(n==m && m%2==1){
        //cout<<A[midRow][midCol]<<"\t";
        result.push_back(A[midRow][midCol]);
    }

	return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

int main()
{
    int m, n;
    m = 5; n=3;
    m = 3; n=5;
    m = 3; n=3;
    m = 4; n=2;
    m = 2; n=4;
    m = 4; n=4;
    vector<vector<int> > mat(m, vector<int>(n, 0));
    for(int i=0, num = 1; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<num<<"\t";
            mat[i][j] = num++;
        }
        cout<<endl;
    }

    cout << "Result: "  << endl;
    vector<int> result = spiralOrder(mat);
    for(int index=0; index<result.size(); index++){
        cout<<result[index]<<"\t";
    }
    return 0;
}
