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
  ListNode *detectCycle(ListNode *head) {
    if(head == NULL) {
      return NULL;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while(true) {
      fast = fast->next;
      if (fast == NULL) {
        return NULL;
      }
      fast = fast->next;
      if(fast == NULL) {
        return NULL;
      }
      slow = slow->next;
      if (fast == slow) { // there is a loop
        ListNode* p = head;
        while(1) {
          if(p == slow) {
            return p;
          }
          p = p->next;
          slow = slow->next;
        }
      }
    }
  }
};
