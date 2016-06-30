/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> q;
        if(root == NULL)
            return;
            
        q.push(root);
        int count = 0;
        int level = 1;
        while(!q.empty()){
            TreeLinkNode* node = q.front();
            q.pop();
            count++;
            if(count == level){
                level*=2;
                node->next=NULL;
                count = 0;
            } else{
                node->next = q.front();
            }
            if(node->left != NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
    }
};
