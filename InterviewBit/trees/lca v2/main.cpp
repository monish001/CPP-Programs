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
TreeNode* _lca(TreeNode* root, const int val1, const int val2, bool& isNode1Present, bool& isNode2Present) {
    isNode1Present = false;
    isNode2Present = false;
    if(root == NULL){
        return NULL;
    }
    int val = root->val;

    bool rtNode1Present = false, rtNode2Present = false, lfNode1Present = false, lfNode2Present = false;
    TreeNode* lfResult = _lca(root->left, val1, val2, lfNode1Present, lfNode2Present);
    TreeNode* rtResult = _lca(root->right, val1, val2, rtNode1Present, rtNode2Present);

    if(val==val1 && val==val2){
        isNode1Present = true;
        isNode2Present = true;
        return root;
    }else if(val == val2){
        isNode2Present = true;
        isNode1Present = rtNode1Present || lfNode1Present;
        return root;
    }else if(val == val1){
        isNode1Present = true;
        isNode2Present = rtNode2Present || lfNode2Present;
        return root;
    }
    if(rtNode1Present && rtNode2Present){
        isNode1Present = true;
        isNode2Present = true;
        return rtResult;
    }
    if(lfNode1Present && lfNode2Present){
        isNode1Present = true;
        isNode2Present = true;
        return lfResult;
    }
    isNode1Present = rtNode1Present || lfNode1Present;
    isNode2Present = lfNode2Present || rtNode2Present;
    if(isNode1Present && isNode2Present){
        return root;
    }
    return NULL;
}
//int Solution::lca(TreeNode* root, int val1, int val2) {
int lca(TreeNode* root, int val1, int val2) {
    TreeNode* result;
    bool isNode1Present;// = false;
    bool isNode2Present;// = false;
    result = _lca(root, val1, val2, isNode1Present, isNode2Present);
    result = isNode1Present && isNode2Present ? result : NULL;
    return result==NULL ? -1 : result->val;
}
int main()
{
    TreeNode* root = new TreeNode(1);
/*
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

///*
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
///*
*/
    cout<<(lca(root, 1, 1)==1);

/*
    cout<<(lca(root, 5, 5)==5);

    cout<<(lca(root, 5, 4)==2); // both in left sub tree
    cout<<(lca(root, 5, 2)==2); // both in left sub tree
    cout<<(lca(root, 2, 6)==1); // in different sub trees
    cout<<(lca(root, 1, 5)==1); // both in left sub tree with root
    cout<<(lca(root, 5, 1)==1); // both in left sub tree with root

    cout<<(lca(root, 2, 10)==-1);
    cout<<(lca(root, 12, 2)==-1);
    cout<<(lca(root, 11, 10)==-1);

*/
    return 0;
}
