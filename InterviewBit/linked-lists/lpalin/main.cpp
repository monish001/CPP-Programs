#include<iostream>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include <climits>
#include <cmath>
using namespace std;

#define ll long long
#define pii pair<int,int>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* nt) : val(x), next(nt) {}
};

int getLength(ListNode* root){
    int count = 0;
    while(root != NULL){
        count++;
        root = root->next;
    }
    return count;
}
bool isOddNumber(int num){
    return num & 1;
}
//int Solution::lPalin(ListNode* root) {
int lPalin(ListNode* root) {
    int len = getLength(root);
    ListNode* newList = NULL;
    for(int index=0; index<len/2; index++){
        ListNode* curNode = root;
        root = root->next;

        curNode->next = newList;
        newList = curNode;
    }
    if(isOddNumber(len)){
        root = root->next;
    }
    for(int index=0; index<len/2; index++){
        if(root->val != newList->val){
            return 0;
        }
        root = root->next;
        newList = newList->next;
    }
    return 1;
}

int main()
{
    ListNode* node3 = new ListNode(1);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);
    cout << lPalin(node1) << endl;
    return 0;
}
