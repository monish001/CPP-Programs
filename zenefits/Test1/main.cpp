#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstring>
using namespace std;

//std::ios_base::sync_with_stdio(false);
string ToString (long long a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}
class stack{
    vector<long long> list;
    public:
    void push(const int val){
        list.push_back(val);
    }
    void pop(){
        if(list.empty()){
            return; // behaviour is not defined.
            string message = "Pop operation not possible. Stack is empty";
            cout<<message<<endl;
            throw message;
        }
        list.pop_back();
    }
    void inc(const int elemCountFromBottom, const int valueToInc){
        int len = list.size();
        if(elemCountFromBottom > len){
            return; // behaviour is not defined.
            string message = "Inc operation not possible. Stack contains less elements than required for the operation.";
            cout<<message<<endl;
            throw message;
        }
        for(int index=0; index<elemCountFromBottom; index++){
            list[index] += valueToInc;
        }
    }
    string peek(){
        if(list.empty()){
            return "EMPTY";
        }
        return ToString(list.back());
    }
};
int main() {
    stack stk;
    int numOfOps;
    scanf("%d", &numOfOps);
    string output = "";

    for(int index=0; index<numOfOps; index++){
        char operation[5];
        char PUSH[] = "push", POP[] = "pop", INC[] = "inc";
        scanf("%s", operation);
        if(operation[1] == 'u'){
            int num;
            scanf("%d", &num);
            stk.push(num);
        }else if(operation[1] == 'o'){
            stk.pop();
        }else if(operation[1] == 'n'){
            int elemCount, val;
            scanf("%d%d", &elemCount, &val);
            stk.inc(elemCount, val);
        }
        output += stk.peek();
        output += "\n";
    }
    cout<<output;

    return 0;
}
