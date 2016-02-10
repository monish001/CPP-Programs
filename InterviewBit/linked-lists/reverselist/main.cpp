#include <iostream>

using namespace std;
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
ListNode* getPointerToNthNode(ListNode* inputList, int m){
    ListNode* curNode = inputList;
    for(int nodeNum = 1; nodeNum < m; nodeNum++){
        curNode = curNode->next;
    }
    return curNode;
}
void reverseTillNthNode(ListNode* inputList, const int n, ListNode*& outReversedListHead, ListNode*& outReversedListEnd, ListNode*& outNsNextNode){
    //ListNode* curNode = inputList;
    outReversedListEnd = outReversedListHead = inputList;
    inputList = inputList->next;
    for(int count = 2; count<=n; count++){
        ListNode* curNode = inputList;
        inputList = inputList->next;
        curNode->next = outReversedListHead;
        outReversedListHead = curNode;
    }
    outNsNextNode = inputList;
}
//ListNode* Solution::reverseBetween(ListNode* inputList, int m, int n) {
ListNode* reverseBetween(ListNode* inputList, int m, int n) {
    ListNode *mPrevNode, *mthNode;
    if(m>1){
        mPrevNode = getPointerToNthNode(inputList, m-1);
        mthNode = mPrevNode->next != NULL ? mPrevNode->next : NULL;
    }else{
        mPrevNode = NULL; // m is 1
        mthNode = inputList;
    }

    ListNode* outNsNextNode = NULL, *outReversedListHead = NULL, *outReversedListEnd = NULL;
    reverseTillNthNode(mthNode, n-m+1, outReversedListHead, outReversedListEnd, outNsNextNode);

    if(mPrevNode != NULL){
        mPrevNode->next = outReversedListHead;
    }
    if(outReversedListEnd != NULL){
        outReversedListEnd->next = outNsNextNode;
    }
    if(mPrevNode == NULL){
        return outReversedListHead;
    }
    return inputList;
}
int main()
{
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* num1 = new ListNode(1, node2);

    ListNode* result = reverseBetween(num1, 2, 4);
    printList(result);
    return 0;
}
