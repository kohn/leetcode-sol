/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    vector<ListNode*> vec;
    TreeNode* list2bst(int start, int end){
        if(end == start)
            return NULL;
        if(end-start == 1)
            return new TreeNode(vec[start]->val);
        int mid = start + (end-start)/2;
        TreeNode* left = list2bst(start, mid);
        TreeNode* right = list2bst(mid+1, end);
        TreeNode* root = new TreeNode(vec[mid]->val);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        while(head != NULL){
            vec.push_back(head);
            head = head->next;
        }
        return list2bst(0, vec.size());
    }
};
