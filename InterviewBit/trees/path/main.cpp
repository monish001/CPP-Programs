#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isLeaf(TreeNode* node){
    if(node == NULL)
        return false;
    return node->right==NULL && node->left==NULL;
}
//int Solution::hasPathSum(TreeNode* A, int B) {
int hasPathSum(TreeNode* A, int B) {
    if(A == NULL){
        return B==0 ? 1 : 0;
    }
    int curVal = A->val;
    if(isLeaf(A)){
        return B==curVal?1:0;
    }
    return (A->left!=NULL && hasPathSum(A->left, B-curVal) || A->right!=NULL && hasPathSum(A->right, B-curVal)) ? 1 : 0;
}
int main()
{
    TreeNode* root = new TreeNode(1000);
    root->left = new TreeNode(200);
    cout<<hasPathSum(root, 1000);
    return 0;
}
