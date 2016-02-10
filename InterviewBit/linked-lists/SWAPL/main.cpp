#include <iostream>

using namespace std;
//Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
   ListNode(int x, ListNode* nx) : val(x), next(nx) {}
};
void printList(ListNode* root){
    while(root != NULL){
        cout<<root->val<<"\t";
        root = root->next;
    }
    cout<<endl;
}
//ListNode* Solution::swapPairs(ListNode* A) {
ListNode* swapPairs(ListNode* inputList) {
    if(inputList == NULL || inputList->next==NULL){
        return inputList;
    }
    ListNode *node1 = inputList, *node2 = inputList->next;
    inputList = node2->next;
    node2->next = node1;
    node1->next = swapPairs(inputList);
    return node2;
}
int main()
{
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(2, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(4, node3);
    ListNode* num1 = new ListNode(1, node2);

    ListNode* result = swapPairs(num1);
    printList(result);
    return 0;
}
