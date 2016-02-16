#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* nt) : val(x), next(nt) {}
};
void appendNode(ListNode* resultNode, ListNode* &result, ListNode* &resultEnd){
    resultNode->next = NULL;
    if(result == NULL){
        result = resultEnd = resultNode;
    }else{
        resultEnd->next = resultNode;
        resultEnd = resultNode;
    }
}
bool getMinListNode(const ListNode* node1, const ListNode* node2){
    bool result;
    if(node1 == NULL){
        //node 2 bigger
        result = true;
    }
    if(node2 == NULL){
        //node 1 bigger
        result = false;
    }
    result = node1->val < node2->val;
    return result;
}

//ListNode* Solution::mergeKLists(vector<ListNode*> &lists) {
ListNode* mergeKLists(vector<ListNode*> &lists) {
    ListNode* resultHead = NULL, *resultEnd = NULL;
    make_heap(lists.begin(), lists.end(), getMinListNode);
    sort_heap(lists.begin(), lists.end(), getMinListNode);
    while(lists.size()){
        // remove list that has min element
        ListNode* minNodeList = lists.front();
        pop_heap(lists.begin(), lists.end(), getMinListNode);
        lists.pop_back();

        ListNode* minNode = minNodeList;
        minNodeList = minNodeList->next;
        minNode->next = NULL;
        appendNode(minNode, resultHead, resultEnd);
        if(minNodeList != NULL){ // if there is only one node
            lists.push_back(minNodeList);
            push_heap(lists.begin(), lists.end(), getMinListNode);
        }
        sort_heap(lists.begin(), lists.end(), getMinListNode);
    }
    return resultHead;
}

void printList(ListNode* list){
    while(list != NULL){
        cout<<list->val<<"\t";
        list = list->next;
    }
    cout<<endl;
}
int main()
{
    ListNode* list1 = new ListNode(1, new ListNode(10, new ListNode(20)));
    ListNode* list2 = new ListNode(4, new ListNode(11, new ListNode(13)));
    ListNode* list3 = new ListNode(3, new ListNode(8, new ListNode(9)));
    printList(list1);
    printList(list2);
    printList(list3);
    vector<ListNode*> lists;
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);
    ListNode* result = mergeKLists(lists);
    printList(result);
    return 0;
}
