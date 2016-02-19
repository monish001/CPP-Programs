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
// return string root, right, left and empty string if not found.
string whereIsNode(TreeNode* root, TreeNode* node){
    //string result;
    if(root == NULL){
        return "";
    }
    if(root == node){
        return "root";
    }
    string rightResult = whereIsNode(root->right, node);
    if(rightResult != ""){
        return "right";
    }
    string  leftResult = whereIsNode(root->left,  node);
    if(leftResult != ""){
        return "left";
    }
    return "";
}
int lca(TreeNode* root, TreeNode* node1, TreeNode* node2){
    if(root == NULL){
        return INT_MIN;
    }
    string node1In = whereIsNode(root, node1), node2In = whereIsNode(root, node2);
    if(
       (node1In == "root"  && (node2In == "right" || node2In == "left")) ||
       (node2In == "root"  && (node1In == "right" || node1In == "left")) ||
       (node1In == "right" &&  node2In == "left") ||
       (node1In == "left"  &&  node2In == "right")
    ){
        return root->val;
    }
    if(node1In == "right" && node2In == "right"){
        return lca(root->right, node1, node2);
    }
    if(node1In == "left" && node2In == "left"){
        return lca(root->left, node1, node2);
    }
    return -1;
}
int main()
{
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout<<lca(root, root->right->right, root->right->left);
    cout<<lca(root, root->right, root->left);
    return 0;
}
