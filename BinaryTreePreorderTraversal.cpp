/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void preorderTraversal(TreeNode* root, vector<int> &ret){
        if(root == NULL)
            return;
        ret.push_back(root->val);
        preorderTraversal(root->left, ret);
        preorderTraversal(root->right, ret);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preorderTraversal(root, ret);
        return ret;
    }
};
