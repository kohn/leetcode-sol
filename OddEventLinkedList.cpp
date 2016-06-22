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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* last_odd  = head;
        ListNode* first_even = head->next;
        ListNode* last_even = head->next;
        while(1){
            if(last_even == NULL || last_even->next == NULL)
                break;
            last_odd->next = last_even->next;
            last_even->next = last_even->next->next;
            last_odd->next->next = first_even;
            last_odd = last_odd->next;
            last_even = last_even->next;
        }
        return head;
    }
};
