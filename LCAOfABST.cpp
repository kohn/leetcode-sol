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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        if(root == p)
            return p;
        if(root == q)
            return q;
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        if(right != NULL && left != NULL)
            return root;
        if(right != NULL && left == NULL)
            return right;
        if(right == NULL && left != NULL)
            return left;
        return NULL;
    }
};
