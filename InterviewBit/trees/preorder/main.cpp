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
//vector<int> Solution::inorderTraversal(TreeNode* root) {
vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> stk;
    stk.push(root);
    vector<int> result;
    while(!stk.empty()){
        TreeNode *curNode = stk.top(), *right = curNode->right, *left = curNode->left;
        stk.pop();
        curNode->right = curNode->left = NULL;
        result.push_back(curNode->val);
        if(right != NULL){
            stk.push(right);
        }
        if(left != NULL){
            stk.push(left);
        }
    }
    return result;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
