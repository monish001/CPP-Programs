//MatrixRotate90.cpp
#include<iostream>

void swapi(char &a, char&b){
    char tmp = a;
    a=b;
    b=tmp;
}

void print(char** a, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            std::cout<<a[i][j];
        }
        std::cout<<"\n";
    }
}

void rotate(char** a, int n){
    for(int i=0; i<n/2; i++){
        int up=i, down=n-1-i;

        //shift corners
        swapi(a[up][up], a[up][down]);
        swapi(a[up][up], a[down][up]);
        swapi(a[down][up], a[down][down]);

        //shift edges
        for(int j=1; j<n-1; j++){
            swapi(a[up][up+j], a[up+j][down]);
            swapi(a[up][up+j], a[down-j][up]);
            swapi(a[down-j][up], a[down][down-j]);
        }
    }
}

int main(){
    int n=3;
    char**a = new char*[n];
    for(int i=0; i<n; i++){
        a[i] = new char[n];
        for(int j=0; j<n; j++)            a[i][j] = 'a'+ 3*i + j;
    }
//    a[0] = "big"; a[1]="fat";   a[2]="cat";
    print(a, n);
    rotate(a,n);
    print(a,n);
    return 0;
}
