//Breadth first search for connected graphs. (All the nodes should be approachable from the vertex selected as node.)
/*
Test case:
    vertex r('r'),s('s'),t('t'),u('u'),v('v'),w('w'),x('x'),y('y');
    r.adj.push_back(&v);
    r.adj.push_back(&s);

    s.adj.push_back(&r);
    s.adj.push_back(&w);

    t.adj.push_back(&w);
    t.adj.push_back(&x);
    t.adj.push_back(&u);

    u.adj.push_back(&t);
    u.adj.push_back(&x);
    u.adj.push_back(&y);

    v.adj.push_back(&r);

    w.adj.push_back(&s);
    w.adj.push_back(&t);
    w.adj.push_back(&x);

    x.adj.push_back(&w);
    x.adj.push_back(&t);
    x.adj.push_back(&u);
    x.adj.push_back(&y);

    y.adj.push_back(&x);
    y.adj.push_back(&u);

    cout<<"BFS traversal order: ";
    bool ans = bfs(s, 'a');
    cout<<"\n"<<"Search Result:"<<ans<<"\n";

    cout<<"Node\tDist\tCOLOR\tPredessor\n";
    cout<<r.getName()<<"\t"<<r.distance<<"\t"<<r.color<<"\t"<<(r.predecessor)->getName()<<"\n";
    cout<<s.getName()<<"\t"<<s.distance<<"\t"<<s.color<<"\t-"<<"\n";//<<(s.predecessor)->getName();
    cout<<t.getName()<<"\t"<<t.distance<<"\t"<<t.color<<"\t"<<(t.predecessor)->getName()<<"\n";
    cout<<u.getName()<<"\t"<<u.distance<<"\t"<<u.color<<"\t"<<(u.predecessor)->getName()<<"\n";
    cout<<v.getName()<<"\t"<<v.distance<<"\t"<<v.color<<"\t"<<(v.predecessor)->getName()<<"\n";
    cout<<w.getName()<<"\t"<<w.distance<<"\t"<<w.color<<"\t"<<(w.predecessor)->getName()<<"\n";
    cout<<x.getName()<<"\t"<<x.distance<<"\t"<<x.color<<"\t"<<(x.predecessor)->getName()<<"\n";
    cout<<y.getName()<<"\t"<<y.distance<<"\t"<<y.color<<"\t"<<(y.predecessor)->getName()<<"\n";

Output:
    BFS traversal order: srwvtxuy
    Search Result:0
    Node    Dist    COLOR   Predessor
    r       1       2       s
    s       0       2       -
    t       2       2       w
    u       3       2       t
    v       2       2       r
    w       1       2       s
    x       2       2       w
    y       3       2       x
*/
#include <list>
#include <queue>
#include <iostream>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
class vertex{
    char name;
public:
    list<vertex*> adj;
    vertex* predecessor;//parent in the bfs tree
    int color;
    int distance;//distance of this vertex from root on the bfs tree
    vertex(char n):color(WHITE), predecessor(NULL), distance(-1), name(n){}
    char getName(){
        return name;
    }
};
/*
bool bfs(vertex root, vertex_to_find)
    set search_status = false
	set color for each vertex = WHITE and distance=INFINITY
	set root.color = GRAY, root.distance = 0 and root.predecessor = NULL
    declare queue Q
    Q.push(root)
    while Q is NOT empty
        vertex temp = Q.pop()
        for each vertex i adjacent to temp
            if i.color = WHITE
                i.color = GRAY, i.predecessor = temp, and i.dist = temp.dist + 1
                Q.push(i)
        temp.color = BLACK
        print temp.getName()
        if(search_status==false && temp.getName() == vertex_to_find)
            search_status=true;
    return search_status;
*/
bool bfs(vertex &root, char item_to_search){
    bool flag = false;
    root.color = GRAY;
    root.distance = 0;
    root.predecessor = NULL;
    queue<vertex*> Q;
    Q.push(&root);
    while(!(Q.empty())){
        vertex* temp = Q.front();
        Q.pop();
        list<vertex*>::iterator i;
        for(i=temp->adj.begin(); i!=temp->adj.end(); ++i){
            if((**i).color == WHITE){
                (**i).color = GRAY;
                (**i).predecessor = temp;
                (**i).distance = temp->distance + 1;
                Q.push(&(**i));
            }
        }
        temp->color = BLACK;
        cout<<temp->getName();
        if(flag==false && temp->getName() == item_to_search)
            flag=true;
    }
    return flag;
}
int main(){
    vertex r('r'),s('s'),t('t'),u('u'),v('v'),w('w'),x('x'),y('y');
    r.adj.push_back(&v);
    r.adj.push_back(&s);

    s.adj.push_back(&r);
    s.adj.push_back(&w);

    t.adj.push_back(&w);
    t.adj.push_back(&x);
    t.adj.push_back(&u);

    u.adj.push_back(&t);
    u.adj.push_back(&x);
    u.adj.push_back(&y);

    v.adj.push_back(&r);

    w.adj.push_back(&s);
    w.adj.push_back(&t);
    w.adj.push_back(&x);

    x.adj.push_back(&w);
    x.adj.push_back(&t);
    x.adj.push_back(&u);
    x.adj.push_back(&y);

    y.adj.push_back(&x);
    y.adj.push_back(&u);

    cout<<"BFS traversal order: ";
    bool ans = bfs(s, 'a');
    cout<<"\n"<<"Search Result:"<<ans<<"\n";

    cout<<"Node\tDist\tCOLOR\tPredessor\n";
    cout<<r.getName()<<"\t"<<r.distance<<"\t"<<r.color<<"\t"<<(r.predecessor)->getName()<<"\n";
    cout<<s.getName()<<"\t"<<s.distance<<"\t"<<s.color<<"\t-"<<"\n";//<<(s.predecessor)->getName();
    cout<<t.getName()<<"\t"<<t.distance<<"\t"<<t.color<<"\t"<<(t.predecessor)->getName()<<"\n";
    cout<<u.getName()<<"\t"<<u.distance<<"\t"<<u.color<<"\t"<<(u.predecessor)->getName()<<"\n";
    cout<<v.getName()<<"\t"<<v.distance<<"\t"<<v.color<<"\t"<<(v.predecessor)->getName()<<"\n";
    cout<<w.getName()<<"\t"<<w.distance<<"\t"<<w.color<<"\t"<<(w.predecessor)->getName()<<"\n";
    cout<<x.getName()<<"\t"<<x.distance<<"\t"<<x.color<<"\t"<<(x.predecessor)->getName()<<"\n";
    cout<<y.getName()<<"\t"<<y.distance<<"\t"<<y.color<<"\t"<<(y.predecessor)->getName()<<"\n";
    return 0;
}
