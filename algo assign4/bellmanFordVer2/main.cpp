/*BELLMAN-FORD ALGO(root, vertex_count)

    set dist[0..vertex_count-1] = INF;
    set dist[root] = 0;
    set dist_prev[0..vertex_count-1] = INF;
    set dist_prev[root] = 0;
    set isSaturated = false;
    for i=1 to vertex_count
        for each edge e = (u,v) // edge from u to v
            if v.dist > u.dist + edge_weight
                v.dist = u.dist + edge_weight
        if dist_prev[] = dist[]
            isSaturated = true
            break loop
        dist_prev <- dist
    if isSaturated = false
        print "Negative cycle present"
    else
        return dist[]

Testcase:
        s   t   x   y   z
    s   999 6   999 7   999
    t   999 999 5   8   -4
    x   999 -2  999 999 999
    y   999 999 -3  999 9
    z   2   999 7   999 999
Output:
    No Negative Cycle Present
    Node    Dist    Predecessor
    s       0       -
    t       2       x
    x       4       y
    y       7       s
    z       -2      t
*/
#define INF 999
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <list>
#include <conio.h>
using namespace std;

template<class T>
bool areArraysEqual(T* array1, T* array2, int count){
    for(int i=0; i<count; i++){
        if( array1[i] != array2[i] )
            return false;
    }
    return true;
}

template<class T>
void copyArray(T* array1, T* array2, int count){
    for(int i=0; i<count; i++)
        array1[i] = array2[i];
}

bool bellman_ford(int root_index, int n, int** mat, int* dist, char* prede, char* name){
//set dist[] and prev_dist[]
    int *dist_prev = new int[n];
    for(int i=0; i<n; i++){
        dist[i] = INF;
        dist_prev[i] = INF;
    }
    dist[root_index] = 0;
    dist_prev[root_index] = 0;

    prede[root_index] = '-';
    bool isSaturated = false;
    for(int i=1; i<=n; i++){//for each iteration
        for(int j=0; j<n; j++){
        for(int k=0; k<n; k++){//for each edge
            if( mat[j][k]<INF && dist[k] > dist[j] + mat[j][k] ){
                dist[k] = dist[j] + mat[j][k];
                prede[k] = name[j];
            }
        }}
        if( areArraysEqual(dist_prev, dist, n) ){
            isSaturated = true;
            break;
        }
        copyArray(dist_prev, dist, n);//dist_prev[] = dist[]
    }
    delete[] dist_prev;
    return isSaturated;
}

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

    cout<<"frm\\to";
    for(int i=0; i<n; i++)
        cout<<"\t"<<name[i];
    int **mat = new int*[n];
    for(int i=0; i<n; i++){//for each row
        cout<<"\n"<<name[i]<<"\t";
        mat[i] = new int[n];
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
        }
    }

//execute
    char* predecessor = new char[n];
    int* dist = new int[n];
    bool isSaturated = bellman_ford(root_index, n, mat, dist, predecessor, name);

//output:
    if(isSaturated == false)
        cout<<"\nNegative Cycle Present";
    else{
        cout<<"\nNo Negative Cycle Present";
        cout<<"\nNode\tDist\tPredecessor";
        for(int i=0; i<n; i++)
            cout<<"\n"<<name[i]<<"\t"<<dist[i]<<"\t"<<predecessor[i];
    }
    delete[] name;
    delete[] mat;
    delete[] dist;
    delete[] predecessor;
    return 0;
}
