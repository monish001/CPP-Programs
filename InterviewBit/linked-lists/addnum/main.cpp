#include<iostream>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long
#define pii pair<int,int>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* nt) : val(x), next(nt) {}
};
void printList(ListNode* root){
    while(root != NULL){
        cout<<root->val<<"\t";
        root = root->next;
    }
    cout<<endl;
}

void appendNode(int digit, ListNode*& head, ListNode*& endOfList){
    ListNode* newNode = new ListNode(digit);
    if(head == NULL){
        head = newNode;
    }else{
        endOfList->next = newNode;
    }
    endOfList = newNode;
}
ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
//ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    int carry = 0;
    ListNode* resultHead = NULL;
    ListNode* endOfList = NULL;
    while(A != NULL || B!=NULL){
        int digitSum = carry;
        if(A!=NULL){
            ListNode* tmpNode = A;
            digitSum+=A->val;
            A = A->next;
            delete tmpNode;
        }
        if(B!=NULL){
            ListNode* tmpNode = B;
            digitSum+=B->val;
            B=B->next;
            delete tmpNode;
        }
        carry = digitSum/10;
        appendNode(digitSum%10, resultHead, endOfList);
        //cout<<"Pushing "<<digitSum%10
    }
    if(carry){
        appendNode(carry, resultHead, endOfList);
    }
    return resultHead;
}

int main()
{
    ListNode* node3 = new ListNode(1);
    ListNode* node2 = new ListNode(9, node3);
    ListNode* num1 = new ListNode(9, node2);
    ListNode* num2 = new ListNode(1);

    ListNode* result = addTwoNumbers(num1, num2);
    printList(result);
    return 0;
}
