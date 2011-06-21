//Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.
#include<iostream>
#include<vector>
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

void compute(char** a, int n){
    vector<bool> r, c;
    for(int i=0; i<n; i++){
        r.push_back(false);
        c.push_back(false);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j] == '0'){
                r[i] = c[j] = true;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(r[i] || c[j]){
                a[i][j]='0';
            }
        }
    }
}

int main(){
    int n=4;
    char**a = new char*[n];
    for(int i=0; i<n; i++){
        a[i] = new char[n];
        for(int j=0; j<n; j++)
            a[i][j] = ((i*i == j)? '0' :('a'+ n*i + j));
    }

    print(a, n);
    for(int i=0; i<n; i++)    cout<<"-";
    cout<<"\n";
    compute(a,n);
    print(a,n);
    return 0;
}
