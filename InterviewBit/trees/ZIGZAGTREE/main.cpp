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
//vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<TreeNode*> level;
    vector<vector<int> > result;
    if(root == NULL){
        return result;
    }
    level.push_back(root);
    while(!level.empty()){
        result.push_back(vector<int>());
        vector<TreeNode*> nextLevel;
        for(int i=0; i<level.size(); i++){
            int lastLevelIndex = result.size()-1;
            TreeNode* curNode = level[i];
            int data = curNode->val;
            // push data from level to result
            result[lastLevelIndex].push_back(data);
            // read next level and init level with that.
            if(curNode->left != NULL){
                nextLevel.push_back(curNode->left);
            }
            if(curNode->right != NULL){
                nextLevel.push_back(curNode->right);
            }
        }
        level = nextLevel;
    }
    int nLevels = result.size();
    for(int level=1; level<nLevels; level += 2){
        reverse(result[level].begin(), result[level].end());
    }
    return result;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
