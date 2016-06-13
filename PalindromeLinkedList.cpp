#include <iostream>
#include <string>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode* head){
    while(head != NULL){
	cout << head->val << "->";
	head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    int length(ListNode* head){
        int length = 0;
        while(head!=NULL){
            head = head->next;
            length++;
        }
        return length;
    }
    ListNode* revert(ListNode* head){
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* new_tail = head->next;
        ListNode* new_head = revert(head->next);
        new_tail->next = head;
        head->next = NULL;
        return new_head;
    }
    
    ListNode* revert(ListNode* head, int start){
        int i = 0;
        if(start==0){
            revert(head);
            return head;
        }
        ListNode* last = head;
        while(last != NULL && i<start-1){
            last = last->next;
            i++;
        }
        if(last != NULL){
            ListNode* tail = last->next;
            if(tail == NULL){
                return last;
            } else{
                ListNode* origin_tail = revert(last->next);
                tail->next = last;
                return origin_tail;
            }
        }  else{
            return NULL;
        }
    }

    ListNode* copy(ListNode* head){
	if(head == NULL)
	    return NULL;
	ListNode* new_node = new ListNode(head->val);
	new_node->next = copy(head->next);
	return new_node;
    }
    
    bool isPalindrome(ListNode* head) {
	head = copy(head);
        int len = length(head);
	cout << "len: " << len << endl;
        if(len == 1 || len == 0)
            return true;

        ListNode* tail;
        if(len % 2 == 1){
            tail = revert(head, len/2+1);
        } else{
            tail = revert(head, len/2);
        }
        for(int i=0; i<len; i+=2){
            if(tail->val != head->val)
                return false;
            tail = tail->next;
            head = head->next;
        }
        return true;
    }
};


int main(int argc, char *argv[]) {
    Solution sol;
    ListNode* l0 = new ListNode(0);
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    l0->next = l1;
    l1->next = l2;
    print(l0);
    cout << sol.isPalindrome(l0) << endl;
    return 0;
}
