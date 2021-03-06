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
class Bst{
    TreeNode* root = NULL;
    void deleteTree(TreeNode* node){
        if(node == NULL){
            return;
        }
        if(node->right != NULL){
            deleteTree(node->right);
        }
        if(node->left != NULL){
            deleteTree(node->left);
        }
        delete node;
    }
    // Returns NULL if tree empty
    // Or returns pointer to the node that contains searchItem
    // Or if searchItem is not present, returns the pointer to the potential parent node of the searchItem.
    TreeNode* find(int searchItem){
        if(root == NULL){
            return NULL;
        }
        TreeNode* node = root, *prevNode = NULL;
        while(node != NULL && node->val!=searchItem){
            prevNode = node;
            if(node->val < searchItem){
                node = node->right;
            }else{
                node = node->left;
            }
        }
        return node == NULL ? prevNode : node;
    }
    void _getInOrderList(TreeNode* root, vector<int>& traversalResult){
        if(root==NULL){
            return;
        }
        if(root->left != NULL){
            _getInOrderList(root->left, traversalResult);
        }
        int result = root->val;
        traversalResult.push_back(result);
//cout<<root->val<<"\t";
        if(root->right != NULL){
            _getInOrderList(root->right, traversalResult);
        }
    }
    void _printInOrder(TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left != NULL){
            _printInOrder(root->left);
        }
        cout<<root->val<<"\t";
        if(root->right != NULL){
            _printInOrder(root->right);
        }
    }
public:
    Bst(){}
    Bst(TreeNode* rt):root(rt){}
    ~Bst(){
        deleteTree(root);
    }
    TreeNode* getRoot(){
        return root;
    }
    // does nothing if data already present in the tree.
    // else insert a new node with given data
    void push(int data){
        TreeNode* searchNode = find(data);
        TreeNode* newNode = new TreeNode(data);
        if(searchNode == NULL){
            root = newNode;
        }else if(searchNode->val > data){
            searchNode->left = newNode;
        }else if(searchNode->val < data){
            searchNode->right = newNode;
        }
    }
    void printInOrder(){
        _printInOrder(root);
    }
    vector<int> getInOrderList(){
        vector<int> traversalResult = vector<int>();
        _getInOrderList(root, traversalResult);
        return traversalResult;
    }
};

//int Solution::kthsmallest(TreeNode* root, int k) {
int kthsmallest(TreeNode* root, int k) {
    vector<int> inOrderList = Bst(root).getInOrderList();
    return inOrderList[k-1];
}

int main()
{
    vector<int> bst;
    bst.push_back(9);
    bst.push_back(8);
    bst.push_back(4);
    bst.push_back(5);
    bst.push_back(6);
    bst.push_back(7);
    bst.push_back(9);
    bst.push_back(4);
    bst.push_back(2);
    bst.push_back(5);

    vector<int> bst2;
    bst2.push_back(1);

    //sortedArrayToBST(bst2);
    return 0;
}

