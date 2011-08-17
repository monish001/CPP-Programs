//: C07:PriorityQueue5.cpp
/*
Test case:
    Enter the number of vertics in the graph: 5
    Enter the name(char) of node..0: s
    Enter the name(char) of node..1: t
    Enter the name(char) of node..2: x
    Enter the name(char) of node..3: y
    Enter the name(char) of node..4: z
    Is s source node (1/0)?1
    Count of adjacent nodes for s: 2
    Enter adjacent node's name(char) and edge weight(int): t 10
    Enter adjacent node's name(char) and edge weight(int): y 5
    Count of adjacent nodes for t: 2
    Enter adjacent node's name(char) and edge weight(int): x 1
    Enter adjacent node's name(char) and edge weight(int): y 2
    Count of adjacent nodes for x: 1
    Enter adjacent node's name(char) and edge weight(int): z 4
    Count of adjacent nodes for y: 3
    Enter adjacent node's name(char) and edge weight(int): t 3
    Enter adjacent node's name(char) and edge weight(int): x 9
    Enter adjacent node's name(char) and edge weight(int): z 2
    Count of adjacent nodes for z: 2
    Enter adjacent node's name(char) and edge weight(int): z 7
    Enter adjacent node's name(char) and edge weight(int): x 6
Output:
    Name    Dist    Predecessor
    s       0       -
    y       5       s
    z       7       y
    t       8       y
    x       9       t
*/
#define INFINITE 999
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <list>
#include <conio.h>
using namespace std;

class vertex;
struct adj_vertex{
    vertex* ver;
    int distance;
    adj_vertex(vertex* u, int d):ver(u),distance(d){}
};
class vertex{
    char name;
public:
    list<adj_vertex> adj;
    int distance;//distance of this vertex from root
    char predecessor;
    vertex(char n, int d):name(n), distance(d), predecessor('-'){}
    vertex(char n):name(n), distance(INFINITE), predecessor('-'){}
    vertex():name('-'), distance(INFINITE), predecessor('-'){}
    void setName(char n){
        name = n;
    }
    char getName()const {
        return name;
    }
};

template<class T, class Compare>
class PQV : public deque<T> {
  Compare comp;
public:
  PQV(Compare cmp = Compare()) : comp(cmp) {
    make_heap(this->begin(),this->end(), comp);
  }
  T& top() {
      make_heap(this->begin(),this->end(), comp);
      return this->front();
    }
  void push(const T& x) {
    this->push_back(x);
    push_heap(this->begin(),this->end(), comp);
  }
  void pop() {
    pop_heap(this->begin(),this->end(), comp);
    this->pop_back();
  }

};

bool operator< (const vertex& v, const vertex& u){
	return v.distance >= u.distance;
}

void dijkstra(PQV< vertex, less<vertex> >& Q, vector<vertex>& S){
    int size = Q.size();
    for(int count=1; count<=size; count++){//while(!(Q.empty())){//while Q is NOT empty
        vertex& u = Q.top();
//        cout<<"Vertex "<<u.getName()<<" poped\n";
        list<adj_vertex>::iterator v;
        for(v=u.adj.begin(); v!=u.adj.end(); ++v){//for(each v in adj[u].first)
//            cout<<"Taversing vertex "<<u.getName()<<" with adj vertex "<<(v->ver)->getName()<<" with condition if "<<(v->ver)->distance<<" > "<<u.distance<<"+"<<v->distance<<"\n";
            if((v->ver)->distance > u.distance + v->distance){
                (v->ver)->predecessor = u.getName();
                (v->ver)->distance = u.distance + v->distance;
            }
        }
        S.push_back(u);//S = S union u
        u.distance = INFINITE;//Q.pop();
    }
}

int main() {
    //ofstream cout("output");
    //ifstream cin("input");
    PQV< vertex, less<vertex> > Q;

    int n;
    cout<<"Enter the number of vertics in the graph: ";
    cin>>n;
    map<char, int> nameToIndex;
    char* name = new char[n];

//declare n vertex objects
    for(int i=0; i<n; i++){
        Q.push_back(vertex());
        cout<<"Enter the name(char) of node.."<<i<<": ";
        cin>>name[i];
        nameToIndex[name[i]] = i;
    }

//initialize n vertex objects
    bool isRootSet=false;
    for(int i=0; i<n; i++){
        Q[i].setName(name[i]);
        if(!isRootSet){
            cout<<"Is "<< Q[i].getName() <<" source node (1/0)?";
            bool root;
            cin>>root;
            if(root){
                isRootSet = true;
                Q[i].distance = 0;
            }
        }
        cout<<"Count of adjacent nodes for "<< Q[i].getName() <<": ";
        int j;
        fflush(stdin);
        cin>>j;
        for(int wt, ki=0; ki<j; ki++){
            char num;
            cout<<"Enter adjacent node's name(char) and edge weight(int): ";
            cin>>num>>wt;
            Q[i].adj.push_back(adj_vertex(&Q[nameToIndex[num]], wt));
        }
    }
    delete[] name;

/*//verify input data
    for(int i=0; i<n; i++){
        std::cout<<"node: "<<Q[i].getName()<<"\tdistance: "<<Q[i].distance<<"\n";
        list<adj_vertex>::iterator v;
        for(v=Q[i].adj.begin(); v!=Q[i].adj.end(); ++v){
            std::cout<<(v->ver)->getName()<<" "<<(v->ver)->distance<<"\n";
        }
    }*/

//execute
    vector<vertex> S;//set S = NULL;
    dijkstra(Q, S);

//print output
    std::cout<<"\nName\tDist\tPredecessor\n";
    vector<vertex>::iterator i;
    for(i=S.begin(); i!=S.end(); i++)
        std::cout<<i->getName()<<"\t"<<i->distance<<"\t"<<i->predecessor<<"\n";
}
