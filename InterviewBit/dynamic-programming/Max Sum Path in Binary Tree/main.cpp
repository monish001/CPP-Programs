#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
// initialises memo[root].first and .second
void _getChildMaxSums(TreeNode* root, map<TreeNode*, pair<int, int> >& memo){
    if(root == NULL){
        return;
    }
//cout<<"0 "<<isPresent(memo, root)<<endl;
    int leftMaxSum, rightMaxSum;
    if(root->left == NULL){
        leftMaxSum = 0;
    }else{
//cout<<"0 "<<isPresent(memo, root->left)<<endl;
        _getChildMaxSums(root->left, memo);
//cout<<"1 "<<isPresent(memo, root->left)<<endl;
        leftMaxSum = max(memo[root->left].first, memo[root->left].second) + root->left->val;
    }
    if(root->right == NULL){
        rightMaxSum = 0;
    }else{
//cout<<"0 "<<isPresent(memo, root->right)<<endl;
        _getChildMaxSums(root->right, memo);
//cout<<"1 "<<isPresent(memo, root->right)<<endl;
        rightMaxSum = max(memo[root->right].first, memo[root->right].second) + root->right->val;
    }
    memo[root] = make_pair(leftMaxSum<0?0:leftMaxSum, rightMaxSum<0?0:rightMaxSum);
//cout<<"1 "<<isPresent(memo, root)<<endl;
}
//int Solution::maxPathSum(TreeNode* root) {
int maxPathSum(TreeNode* root) {
    map<TreeNode*, pair<int, int> > memo;
    _getChildMaxSums(root, memo);

    int result = INT_MIN;
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
        TreeNode* curNode = stk.top(); stk.pop();
        if(curNode==NULL){
            continue;
        }
        int curSum = curNode->val + memo[curNode].first + memo[curNode].second;
        result = max(result, curSum);
        stk.push(curNode->left);
        stk.push(curNode->right);
    }
    return result;
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->left->right = new TreeNode(5);
    cout<<maxPathSum(root)<<endl;

    TreeNode* n47 = new TreeNode(47);
    TreeNode* n42 = n47->left = new TreeNode(42);
    TreeNode* n41 = n42->left = new TreeNode(41);
    TreeNode* n44 = n42->right = new TreeNode(44);
    TreeNode* n40 = n41->left = new TreeNode(40);
    TreeNode* n43 = n44->left = new TreeNode(43);
    TreeNode* n45 = n44->right = new TreeNode(45);
    TreeNode* n46 = n45->right = new TreeNode(46);
    cout<<maxPathSum(n47)<<endl;

    return 0;
}
