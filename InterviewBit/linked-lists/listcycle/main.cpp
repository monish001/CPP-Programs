#include <iostream>

using namespace std;
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
   ListNode(int x, ListNode* nx) : val(x), next(nx) {}
};

//ListNode* Solution::detectCycle(ListNode* inputList) {
ListNode* detectCycle(ListNode* inputList) {
    if(inputList == NULL){
        return NULL;
    }
    ListNode *slow = inputList, *fast = inputList;
    int slowVal, fastVal;
    slowVal = slow->val;
    fastVal = fast->val;
    do{
        if(fast->next == NULL || slow->next == NULL || fast->next->next == NULL){
            return NULL; // no loop
        }
        slow = slow->next; slowVal = slow->val;
        fast = fast->next; fastVal = fast->val;
        fast = fast->next; fastVal = fast->val;
        //cout<<"slow val:"<<slow->val<<"\tfast val:"<<fast->val<<endl;
        if(slow == fast){
            break; // there exists a loop
        }
    }while(1);
    //cout<<"Meeting node is "<<slow->val<<endl;
    slow = inputList;
    slowVal = slow->val;
    fastVal = fast->val;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
        slowVal = slow->val;
        fastVal = fast->val;
    }
    return slow;
}
int main()
{
    ListNode* node4 = new ListNode(8);
    ListNode* node3 = new ListNode(7, node4);
    ListNode* node2 = new ListNode(6, node3);
    node4->next = node2;
    ListNode* list1 = new ListNode(1, node2);
/*
    ListNode* nodeD = new ListNode(8);
    ListNode* nodeC = new ListNode(7, nodeD);
    ListNode* nodeB = new ListNode(6, nodeC);
    nodeD->next = nodeC;
    ListNode* list2 = new ListNode(1, nodeB);
*/
/*
    ListNode* nodeDD = new ListNode(8);
    ListNode* nodeCC = new ListNode(7, nodeDD);
    ListNode* nodeBB = new ListNode(6, nodeCC);
    ListNode* list3 = new ListNode(1, nodeBB);
    nodeDD->next = list3;
*/
    ListNode* result = detectCycle(list1);
    cout<<result->val;
    return 0;
}
