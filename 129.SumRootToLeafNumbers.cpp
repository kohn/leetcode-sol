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
    void number(TreeNode* root, vector<int> &res, int num){
        num = num*10 + root->val;
        if(root->left == NULL && root->right == NULL){
            res.push_back(num);
            return;
        }
        if(root->left != NULL)
            number(root->left, res, num);
        if(root->right != NULL)
            number(root->right, res, num);
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
        vector<int> res;
        number(root, res, 0);
        int sum = 0;
        for(int n : res)
            sum += n;
        return sum;
    }
};
