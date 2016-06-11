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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next==NULL)
            return false;
        ListNode *p = head;
        ListNode *q = head->next;
        while(p != q){
            p = p->next;
            if(p == NULL)
                return false;
            q = q->next;
            if(q == NULL)
                return false;
            q = q->next;
            if(q == NULL)
                return false;
        }
        return true;
    }
};
