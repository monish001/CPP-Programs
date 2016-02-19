#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// flattens tree at root and tree at append. Appends the append to flattened root.
TreeNode* _flatten(TreeNode* root, TreeNode* append){
    if(root == NULL){
        return append==NULL ? NULL : _flatten(append, NULL);
    }
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    TreeNode *rightFlattened = _flatten(right, append);
    root->left = NULL;
    root->right = _flatten(left, rightFlattened);
    return root;
}
void append(TreeNode* newNode, TreeNode*& head, TreeNode*& endOfList){
    if(head == NULL){
        head = newNode;
    }else{
        endOfList->right = newNode;
    }
    endOfList = newNode;
}
TreeNode* _flatten2(TreeNode* root){
    stack<TreeNode*> stk;
    stk.push(root);
    TreeNode* resultHead = NULL, *resultEnd = NULL;
    while(!stk.empty()){
        TreeNode* curNode = stk.top(); stk.pop();
        if(curNode == NULL){
            continue;
        }
        TreeNode *right = curNode->right, *left = curNode->left;
        // process curNode
        curNode->right = curNode->left = NULL;
//cout<<"Processing "<<curNode->val<<"\t";
        append(curNode, resultHead, resultEnd);

        if(right !=NULL){
            stk.push(right);
        }
        if(left != NULL){
            stk.push(left);
        }
    }
    return resultHead;
}
//TreeNode* Solution::flatten(TreeNode* root) {
TreeNode* flatten(TreeNode* root) {
    return _flatten(root, NULL);
    //return _flatten2(root);
}
void printFlattenedTree(TreeNode* root){
    if(root == NULL){
        return;
    }
    cout<<root->val<<"\t";
    printFlattenedTree(root->right);
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->left->right = new TreeNode(5);

    TreeNode* n47 = new TreeNode(47);
    TreeNode* n42 = n47->left = new TreeNode(42);
    TreeNode* n41 = n42->left = new TreeNode(41);
    TreeNode* n44 = n42->right = new TreeNode(44);
    TreeNode* n40 = n41->left = new TreeNode(40);
    TreeNode* n43 = n44->left = new TreeNode(43);
    TreeNode* n45 = n44->right = new TreeNode(45);
    TreeNode* n46 = n45->right = new TreeNode(46);
    printFlattenedTree(flatten(n47));
    return 0;
}
