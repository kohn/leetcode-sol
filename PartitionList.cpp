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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* node = head;
        ListNode* last = NULL;
        ListNode* insert_point = NULL;
        while(node != NULL){
            if(node->val < x){
                if(last == NULL){
                    last = node;
                    insert_point = node;
                    node = node->next;
                } else{
                    if(last == insert_point){
                        last = node;
                        insert_point = node;
                        node = node->next;
                        continue;
                    }
                    ListNode* next = node->next;
                    last->next = node->next;
                    if(insert_point == NULL){
                        node->next = head;
                        head = node;
                    } else{
                        node->next = insert_point->next;
                        insert_point->next = node;
                    }
                    insert_point = node;
                    node = next;
                }
            } else{
                last = node;
                node = node->next;
            }
        }
        return head;
    }
};
