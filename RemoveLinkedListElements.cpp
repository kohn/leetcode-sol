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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;
        if(head->val == val)
            return removeElements(head->next, val);
        ListNode* last = head;
        ListNode* node = head->next;
        while(node != NULL){
            if(node->val == val){
                last->next = node->next;
            } else{
                last = node;
            }
            node = node->next;
        }
        return head;
    }
};
