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
    void findPath(vector<vector<int>> &result, vector<int> &prefix, TreeNode *root, int sum) {          
        if(root == NULL) {
            return;
        }
        
        prefix.push_back(root->val);
        if (root->left != NULL) {
            findPath(result, prefix, root->left, sum-root->val);
        }
        
        if (root->right != NULL) {
            findPath(result, prefix, root->right, sum-root->val);
        }
        
        if (root->left == NULL && root->right == NULL && sum==root->val) {
            result.push_back(prefix);
        }
        prefix.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        findPath(result, vector<int>(),  root, sum);
        return result;
    }
};
