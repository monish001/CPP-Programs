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
//vector<int> Solution::postorderTraversal(TreeNode* root) {
vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> stk;
    stk.push(root);
    vector<int> result;
    while(!stk.empty()){
        TreeNode *curNode = stk.top(); stk.pop();
        if(curNode == NULL){
            continue;
        }
        TreeNode *left = curNode->left, *right = curNode->right;
        curNode->right = curNode->left = NULL;

        if(right == NULL && left == NULL){
            result.push_back(curNode->val);
        }else{
            stk.push(curNode);
            if(right!=NULL) stk.push(right);
            if(left!=NULL) stk.push(left);
        }
    }
    return result;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
