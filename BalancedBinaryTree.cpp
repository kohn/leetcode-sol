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
    int maxDiffer(TreeNode* root, int &height){
        if(root == NULL){
            height = 0;
            return 0;
        }
            
        int left_height, right_height;
        if(maxDiffer(root->left, left_height) > 1)
            return 2;
        if(maxDiffer(root->right, right_height) > 1)
            return 2;
        height = max(left_height, right_height)+1;
        return abs(left_height-right_height);
    }
    bool isBalanced(TreeNode* root) {
        int height;
        return maxDiffer(root, height)<=1;
    }
};
