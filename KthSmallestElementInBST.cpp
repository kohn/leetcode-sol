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
    int kthSmallest(TreeNode* root, int k, int &value){
        if(root == NULL)
            return 0;
        int left_count = kthSmallest(root->left, k, value);
        if(left_count >= k)
            return left_count+1;
        else if(left_count == k-1){
            value = root->val;
            return left_count+1;
        } else{
            left_count++;
            int right_count = kthSmallest(root->right, k-left_count, value);
            return left_count+right_count;
        }
        return -1;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int value;
        kthSmallest(root, k, value);
        return value;
    }
};
