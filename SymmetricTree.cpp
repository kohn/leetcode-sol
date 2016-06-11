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
    bool isSymmertric(TreeNode* left, TreeNode* right){
        if(left == right)
            return true;
        if(left == NULL || right == NULL)
            return false;
            
        if(left->val != right->val)
            return false;
        return (isSymmertric(left->right, right->left) && isSymmertric(left->left, right->right));
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isSymmertric(root->left, root->right);
    }
};
