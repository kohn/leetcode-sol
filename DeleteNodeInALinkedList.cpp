/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == NULL)
            return;
        ListNode* next = node->next;
        if(next == NULL)
            return;
        node->next = next->next;
        node->val = next->val;
    }
};
