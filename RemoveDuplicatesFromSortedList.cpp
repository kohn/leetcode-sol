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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* origin = head;
        while(head != NULL){
            ListNode* next = head->next;
            while(next != NULL && next->val==head->val)
                next = next->next;
            head->next = next;
            head = next;
        }
        return origin;
    }
};
