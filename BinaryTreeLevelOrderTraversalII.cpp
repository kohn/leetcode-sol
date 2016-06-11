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
    void search(vector<vector<int> > &ret, TreeNode* root, int level){
        if(root == NULL)
            return;
        if(ret.size() == level)
            ret.push_back(vector<int>());
        ret[level].push_back(root->val);
        search(ret, root->left, level+1);
        search(ret, root->right, level+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ret;
        search(ret, root, 0);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
