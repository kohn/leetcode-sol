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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
            
        ListNode *p1=head, *p2=head->next, *parent=NULL;
        while(p2!=NULL){
            if(parent == NULL)
                head = p2;
            else{
                parent->next = p2;
                
            }
            p1->next = p2->next;
            p2->next = p1;
            parent = p1;    
            p1 = p1->next;
            if(p1 == NULL)
                p2 = NULL;
            else
                p2 = p1->next;
        }
        return head;
    }
};

int main(int argc, char *argv[]){
    
    return 0;
}
