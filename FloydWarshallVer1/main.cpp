#define INF 999
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <list>
#include <conio.h>
using namespace std;

int main()
{
    ifstream cin("input");
//input
    int n;
    cout<<"Enter the number of vertics in the graph: ";
    cin>>n;
    map<char, int> nameToIndex;
    char* name = new char[n];

//declare n vertex names
    for(int i=0; i<n; i++){
        cout<<"Enter the name(char) of node.."<<i<<": ";
        cin>>name[i];
        nameToIndex[name[i]] = i;
    }

    cout<<"Enter the name of source node.. ";
    char root_name;
    cin>>root_name;
    int root_index = nameToIndex[root_name];

    cout<<"Enter adjcency matrix\nfrm\\to";
    for(int i=0; i<n; i++)
        cout<<"\t"<<name[i];
    int **mat = new int*[n];
    int **path = new int*[n];
    for(int i=0; i<n; i++){//for each row
        cout<<"\n"<<name[i]<<"\t";
        mat[i] = new int[n];
        path[i] = new int[n];
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
            path[i][j] = mat[i][j];
        }
    }

    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
    for(int k=0; k<n; k++){
        if(path[i][j] > path[i][k] + path[k][j])
            path[i][j] = path[i][k] + path[k][j];
    }

    cout<<"\nOUTPUT: Weight(i,i) = Negative means NEGATIVE CYCLE PRESENT:\nfrm\\to";
    for(int i=0; i<n; i++)
        cout<<"\t"<<name[i];
    for(int i=0; i<n; i++){//for each row
        cout<<"\n"<<name[i]<<"\t";
        for(int j=0; j<n; j++){
            cout<<path[i][j]<<"\t";
        }
    }



    delete[] name;
    delete[] path;
    delete[] mat;
    return 0;
}
