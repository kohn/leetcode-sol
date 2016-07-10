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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ret;
        if(root == NULL)
            return ret;
        q.push(root);
        int this_level_count = 1;
        int count = 0;
        int next_level_count = 0;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                next_level_count++;
            }
            if(node->right){
                q.push(node->right);
                next_level_count++;
            }
            count++;
            if(count == this_level_count){
                ret.push_back(node->val);
                count = 0;
                this_level_count = next_level_count;
                next_level_count = 0;
            }
        }
        return ret;
    }
};
