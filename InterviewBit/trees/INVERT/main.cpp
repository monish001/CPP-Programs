#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void _invertTree(TreeNode* root) {
    if(root == NULL){
        return;
    }
    TreeNode *right = root->right, *left = root->left;
    root->left = right; root->right = left;
    _invertTree(right);
    _invertTree(left);
}
TreeNode* Solution::invertTree(TreeNode* root) {
    _invertTree(root);
    return root;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
