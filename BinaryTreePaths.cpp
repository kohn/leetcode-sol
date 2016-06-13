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
    string toString(int a){
        if(a == 0)
            return  "0";
        string str;
        int b=a;
        if(a<0){
            a = -a;
        }
        while(a!=0){
            str.insert(0, 1, '0'+a%10);
            a /= 10;
        }
        
        if(b<0)
            str.insert(0, 1, '-');
        return str;
    }
    void search(TreeNode* root, string path, vector<string> &res){
        if(root == NULL)
            return;
            
        path.append("->");
        path.append(toString(root->val));
        if(root->left != NULL)
            search(root->left, path, res);
        
        if(root->right != NULL)
            search(root->right, path, res);
            
        if(root->left == NULL && root->right == NULL)
            res.push_back(path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root ==NULL)
            return res;
        string path = toString(root->val);
        if(root->left != NULL)
            search(root->left, path, res);
        if(root->right != NULL)
            search(root->right, path, res);
        if(root->left == NULL && root->right == NULL)
            res.push_back(path);
        return res;
    }
};
