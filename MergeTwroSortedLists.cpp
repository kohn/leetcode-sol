#include <iostream>
#include <string>
using namespace std;

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *tail = NULL;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                if(head == NULL){
                    head = l1;
                    tail = head;
                }
                else{
                    tail->next = l1;
                    tail = l1;
                }
                l1 = l1->next;
            } else{
                if(head == NULL){
                    head = l2;
                    tail = head;
                }
                else{
                    tail->next = l2;
                    tail = l2;
                }
                l2 = l2->next;
            }
        }
        
        if(l1 != NULL){
            if(head == NULL)
                head = l1;
            else
                tail->next = l1;
        } else if(l2 != NULL){
            if(head == NULL)
                head = l2;
            else
                tail->next = l2;
        }
        return head;
    }
};

int main(int argv, char *argv[]){
    
    return 0;
}
