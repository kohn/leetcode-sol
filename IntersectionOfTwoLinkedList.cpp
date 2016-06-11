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
    
    int length(ListNode* head){
        int len = 0;
        while(head != NULL){
            head = head->next;
            len++;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = length(headA);
        int lengthB = length(headB);
        if(lengthA >= lengthB){
            ListNode* pa = headA;
            ListNode* pb = headB;
            for(int i=0; i<lengthA-lengthB; i++){
                pa = pa->next;
            }
            
            while(pa!=NULL && pb != NULL){
                if(pa == pb){
                    return pa;
                }
                pa = pa->next;
                pb = pb->next;
            }
            return NULL;
        } else{
            return getIntersectionNode(headB, headA);
        }
    }
};
