//Question 3. Optimal (Polygon) Triangulation Problem.
/*
Test case:
	int n=4;
	point* polygon = new point[n];
	polygon[0].first = 0;	polygon[0].second = 0;
	polygon[1].first = 10;	polygon[1].second = 0;
	polygon[2].first = 20;	polygon[2].second = 10;
	polygon[3].first = 10;	polygon[3].second = 10;
	//Getting weight for minimum weight triangulation.
	double min_weight;
    min_weight = GetTriangulationMinWeight(polygon, n);
	cout<<"\nWeight for the minimum triangulation is "<<min_weight;
Output:
0       46.5028 -1
-1      0       34.1421
-1      -1      0
-------------------------------
0       46.5028 54.1421
-1      0       34.1421
-1      -1      0
-------------------------------
Weight for the minimum triangulation is 54.1421

Test case:
//Initializing the polygon
	int n=6;
	point* polygon = new point[n];
	polygon[0].first = 0;	polygon[0].second = 4;
	polygon[1].first = 3;	polygon[1].second = 8;
	polygon[2].first = 8;	polygon[2].second = 8;
	polygon[3].first = 11;	polygon[3].second = 4;
	polygon[4].first = 8;	polygon[4].second = 0;
	polygon[4].first = 3;	polygon[4].second = 0;
//Getting weight for minimum weight triangulation.
	double min_weight;
    min_weight = GetTriangulationMinWeight(polygon, n);
	cout<<"\nWeight for the minimum triangulation is "<<min_weight;/*
Output:
0       18.9443 -1      -1      -1
-1      0       18.9443 -1      -1
-1      -1      0       23.3783 -1
-1      -1      -1      0       23.649
-1      -1      -1      -1      0
-------------------------------
0       18.9443 32.8885 -1      -1
-1      0       18.9443 36.8328 -1
-1      -1      0       23.3783 35.8122
-1      -1      -1      0       23.649
-1      -1      -1      -1      0
-------------------------------
0       18.9443 32.8885 49.8328 -1
-1      0       18.9443 36.8328 47.8328
-1      -1      0       23.3783 35.8122
-1      -1      -1      0       23.649
-1      -1      -1      -1      0
-------------------------------
0       18.9443 32.8885 49.8328 57.8328
-1      0       18.9443 36.8328 47.8328
-1      -1      0       23.3783 35.8122
-1      -1      -1      0       23.649
-1      -1      -1      -1      0
-------------------------------
Weight for the minimum triangulation is 57.8328
*/
/*
Minimum-Weight-Triangulation(P)
	for i = 1 to n - 1 do T[i, i + 1] = 0
	for gap = 2 to n - 1
		for i = 1 to n - gap do
			j = i + gap
			T[i, j] = min from k=i+1 to j-1 (T[i, k] + T[k, j] + dPi,Pk + dPk,Pj )
	return T[1, n]
*/
#include<iostream>
#include<cmath>
using namespace std;
typedef pair<int, int> point;
#define square(x) ((x)*(x))
double getDistance(point pt1, point pt2){
	int x_diff = pt1.first  - pt2.first ;
	int y_diff = pt1.second - pt2.second;
	return sqrt( square(x_diff) + square(y_diff) );
}
template<class Type>
Type** make_mat(int x, int y){
	Type **val = new Type*[x];
	for(int i=0; i<x; i++){//for each row
		val[i] = new Type[y];
		for(int j=0; j<y; j++)//for each col
			val[i][j]=-1;
	}
	return val;
}
template <class type>
void show2Darray(type** val, int x, int y){
	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++)
			cout<<val[i][j]<<"\t";
		cout<<"\n";
	}
	cout<<"-------------------------------\n";
}
double GetTriangulationMinWeight(point* polygon, int n){
	double** Table = make_mat<double>(n+1,n+1);
	for(int i=0; i<n+1; i++)
		Table[i][i] = 0;
	for(int gap=2; gap<=n-1; gap++){
		for(int j,i=0; i<=n+1-gap; i++){
			j = i+gap;
			double temp;
			for(int k=i+1; k<=j-1; k++){
				temp = Table[i][k-1]+Table[k][j-1]+getDistance(polygon[i%n], polygon[k%n])+getDistance(polygon[k%n], polygon[j%n]);
				if(Table[i][j-1] == -1)
					Table[i][j-1] = temp;
				else if(Table[i][j-1]>temp)
					Table[i][j-1]=temp;
			}
			if(gap == 2){
                Table[i][j-1] += getDistance(polygon[i], polygon[j]);
			}
		}
		show2Darray(Table, n+1, n+1);
	}
	double min_weight = Table[0][n-2];
	delete []Table;
	return min_weight;
}
int main(){
	int n=4;
	point* polygon = new point[n];
	polygon[0].first = 0;	polygon[0].second = 0;
	polygon[1].first = 10;	polygon[1].second = 0;
	polygon[2].first = 20;	polygon[2].second = 10;
	polygon[3].first = 10;	polygon[3].second = 10;
	//Getting weight for minimum weight triangulation.
	double min_weight;
    min_weight = GetTriangulationMinWeight(polygon, n);
	cout<<"Weight for the minimum triangulation is "<<min_weight;
	cout<<"Press any key t";
	getchar();
	return 0;
}
