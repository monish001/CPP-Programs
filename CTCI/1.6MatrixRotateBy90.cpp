//MatrixRotate90.cpp
#include<iostream>
using namespace std;
void swap(char &a, char&b){
    std::swap(a,b);
//    cout<<a<<" and "<<b<<" swapped.\n";
}

void print(char** a, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j];
        }
        cout<<"\n";
    }
}

void rotate(char** a, int n){
    for(int i=0; i<n/2; i++){
        int up=i, down=n-1-i;

        //shift corners
        swap(a[up][up], a[up][down]);
        swap(a[up][up], a[down][up]);
        swap(a[down][up], a[down][down]);

        //shift edges
        for(int j=up+1; j<down; j++){
            swap(a[up][up+j], a[up+j][down]);
            swap(a[up][up+j], a[down-j][up]);
            swap(a[down-j][up], a[down][down-j]);
        }
    }
}

int main(){
    int n=4;
    char**a = new char*[n];
    for(int i=0; i<n; i++){
        a[i] = new char[n];
        for(int j=0; j<n; j++)            a[i][j] = 'a'+ n*i + j;
    }

    print(a, n);
    for(int i=0; i<n; i++)    cout<<"-";
    cout<<"\n";
    rotate(a,n);
    print(a,n);
    return 0;
}
