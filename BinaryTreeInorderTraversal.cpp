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
    void inorderTraversal(TreeNode* root, vector<int> &ret){
        if(root == NULL)
            return;
        inorderTraversal(root->left, ret);
        ret.push_back(root->val);
        inorderTraversal(root->right, ret);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        inorderTraversal(root, ret);
        return ret;
    }
};
