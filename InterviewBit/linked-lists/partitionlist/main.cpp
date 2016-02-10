#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
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

void append(ListNode* newNode, ListNode*& head, ListNode*& endOfList){
    if(head == NULL){
        head = newNode;
    }else{
        endOfList->next = newNode;
    }
    endOfList = newNode;
}
ListNode* mergeLists(ListNode*& list1, ListNode*& list1End, ListNode*& list2, ListNode*& list2End){
    if(list1 == NULL)
        return list2;
    list1End->next = list2;
    return list1;
}
ListNode* partition(ListNode* inputList, int partitionVal) {
//ListNode* Solution::partition(ListNode* inputList, int partitionVal) {
    ListNode *lsThList = NULL, *lsThListEnd = NULL, *grThEqList = NULL, *grThEqListEnd = NULL;
    while(inputList != NULL){
        ListNode* curNode = inputList;
        inputList = inputList->next;
        curNode->next = NULL;
        if(curNode->val < partitionVal){
            append(curNode, lsThList, lsThListEnd);
        }else{
            append(curNode, grThEqList, grThEqListEnd);
        }
    }
    return mergeLists(lsThList, lsThListEnd, grThEqList, grThEqListEnd);
}
int main()
{
    ListNode* node6 = new ListNode(2);
    ListNode* node5 = new ListNode(5, node6);
    ListNode* node4 = new ListNode(2, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(4, node3);
    ListNode* num1 = new ListNode(1, node2);

    ListNode* result = partition(num1, 3);
    printList(result);
    return 0;
}
