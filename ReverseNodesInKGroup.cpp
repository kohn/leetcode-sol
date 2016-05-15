#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverse_group(ListNode* start, ListNode* end){
        if(start == end)
            return start;

        ListNode* head = start;
        ListNode* node = start->next;
        ListNode* parent = start;
        ListNode* end_next = end->next;
        while(node != end_next){
            parent->next = node->next;
            node->next = head;
            head = node;
            node = parent->next;
        }
        return head;
    }
    
    ListNode* do_reverse(ListNode* node, int k, ListNode* start, int n){
        if(n == 0){
            ListNode* new_head = reverse_group(start, node);
            start->next = do_reverse(start->next, k, start->next, k-1);
            return new_head;
        } else if(node == NULL){
            return start;
        } else{
            if(node->next == NULL){
                return start;
            } else{
                return do_reverse(node->next, k, start, n-1);
            }
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        else
            return do_reverse(head, k, head, k-1);
    }
};


int main(int argc, char *argv[])
{
    ListNode *head = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    head->next = node2;
    Solution sol;
    ListNode *new_head = sol.reverseKGroup(head, 2);

    while(new_head != NULL){
        cout << new_head->val << " ";
        new_head = new_head->next;
    }
    return 0;
}
