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
bool _isSameTree(TreeNode* root1, TreeNode* root2) {
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    return root1->val == root2->val && _isSameTree(root1->right, root2->right) && _isSameTree(root1->left, root2->left);
}
//int Solution::isSameTree(TreeNode* root1, TreeNode* root2) {
int isSameTree(TreeNode* root1, TreeNode* root2) {
    return _isSameTree(root1, root2) ? 1 : 0;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
