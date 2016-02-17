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
// returns -1 if root not a balanced tree,
// else returns height of the balance tree.
int _isBalanced(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int rTreeHt = _isBalanced(root->right);
    int lTreeHt = _isBalanced(root->left );
    bool isRootBalance = abs(lTreeHt-rTreeHt) <= 1;
    if(rTreeHt == -1 || lTreeHt == -1 || !isRootBalance){
        return -1;
    }
    return 1 + max(rTreeHt, lTreeHt);
}
//int Solution::isBalanced(TreeNode* root) {
int isBalanced(TreeNode* root) {
    return _isBalanced(root) == -1 ? 0 : 1;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
