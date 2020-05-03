/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count;
    void findPath(TreeNode* root, int sum, int need, bool continuous) {
        if (root == NULL) {
            return;
        }
        
        if(need == root->val) {
            count++;
        }
        
        if (root->left != NULL){
            findPath(root->left, sum, need-root->val, true);
            if (!continuous) {
                findPath(root->left, sum, sum, false);
            }
        }
        
        if (root->right != NULL) {
            findPath(root->right, sum, need-root->val, true);
            if (!continuous) {
                findPath(root->right, sum, sum, false); 
            }
        }
    }
    int pathSum(TreeNode* root, int sum) {
        count = 0;
        findPath(root, sum, sum, false);
        return count;
    }
};
