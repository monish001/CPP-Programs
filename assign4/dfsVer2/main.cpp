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

    cout<<"DFS traversal order: ";
    bool ans = dfs(s, 'a');
    cout<<"\n"<<"Search Result:"<<ans<<"\n";

    cout<<"Node\tCOLOR\tPredessor\n";
    cout<<r.getName()<<"\t"<<r.color<<"\t"<<(r.predecessor)->getName()<<"\n";
    cout<<s.getName()<<"\t"<<s.color<<"\t-"<<"\n";//<<(s.predecessor)->getName();
    cout<<t.getName()<<"\t"<<t.color<<"\t"<<(t.predecessor)->getName()<<"\n";
    cout<<u.getName()<<"\t"<<u.color<<"\t"<<(u.predecessor)->getName()<<"\n";
    cout<<v.getName()<<"\t"<<v.color<<"\t"<<(v.predecessor)->getName()<<"\n";
    cout<<w.getName()<<"\t"<<w.color<<"\t"<<(w.predecessor)->getName()<<"\n";
    cout<<x.getName()<<"\t"<<x.color<<"\t"<<(x.predecessor)->getName()<<"\n";
    cout<<y.getName()<<"\t"<<y.color<<"\t"<<(y.predecessor)->getName()<<"\n";

Output:
    DFS traversal order: swxyutrv
    Search Result:0
    Node    COLOR   Predessor
    r       2       s
    s       2       -
    t       2       w
    u       2       x
    v       2       r
    w       2       s
    x       2       w
    y       2       x
*/
#include <list>
#include <stack>
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
    vertex(char n):color(WHITE), predecessor(NULL), name(n){}
    char getName(){
        return name;
    }
};
bool dfs(vertex &root, char key){
    bool flag = false;
    root.color = GRAY;
    root.predecessor = NULL;
    stack<vertex*> stk;
    stk.push(&root);
    while(!(stk.empty())){
        vertex* temp = stk.top();
        stk.pop();
        list<vertex*>::iterator i;
        for(i=temp->adj.begin(); i!=temp->adj.end(); ++i){
            if((**i).color == WHITE){
                (**i).color = GRAY;
                (**i).predecessor = temp;
                stk.push(&(**i));
            }
        }
        temp->color = BLACK;
        cout<<temp->getName();
        if(flag==false && temp->getName() == key)
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

    cout<<"DFS traversal order: ";
    bool ans = dfs(s, 'a');
    cout<<"\n"<<"Search Result:"<<ans<<"\n";

    cout<<"Node\tCOLOR\tPredessor\n";
    cout<<r.getName()<<"\t"<<r.color<<"\t"<<(r.predecessor)->getName()<<"\n";
    cout<<s.getName()<<"\t"<<s.color<<"\t-"<<"\n";//<<(s.predecessor)->getName();
    cout<<t.getName()<<"\t"<<t.color<<"\t"<<(t.predecessor)->getName()<<"\n";
    cout<<u.getName()<<"\t"<<u.color<<"\t"<<(u.predecessor)->getName()<<"\n";
    cout<<v.getName()<<"\t"<<v.color<<"\t"<<(v.predecessor)->getName()<<"\n";
    cout<<w.getName()<<"\t"<<w.color<<"\t"<<(w.predecessor)->getName()<<"\n";
    cout<<x.getName()<<"\t"<<x.color<<"\t"<<(x.predecessor)->getName()<<"\n";
    cout<<y.getName()<<"\t"<<y.color<<"\t"<<(y.predecessor)->getName()<<"\n";
    return 0;
}
