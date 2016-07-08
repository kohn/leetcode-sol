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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL)  
            return head;
        ListNode* current = head->next;
        ListNode* last = head;
        while(current != NULL){
            ListNode* node = head;
            ListNode* node_last = NULL;
            while(node != current){
                if(node->val > current->val){
                    break;
                } else {
                    node_last = node;
                    node = node->next;
                }
            }
            if(node != current){
                last->next = current->next;
                if(node_last != NULL){
                    node_last->next = current;
                    current->next = node;
                } else {
                    current->next = node;
                    head = current;
                }
                current = last;
            }
            last = current;
            current = current->next;
        }
        return head;
    }
};
