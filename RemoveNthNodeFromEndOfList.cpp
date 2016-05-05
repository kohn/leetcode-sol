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
    int Length(ListNode *head){
        int length = 0;
        while(head!=NULL){
            head = head->next;
            length++;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = Length(head);
        int num = length-n;
        ListNode* origin = head;
        ListNode *parent = NULL;
        while(num--){
            parent = head;
            head = head->next;
        }
        if(parent == NULL)
            return head->next;
        parent->next = head->next;
        return origin;
    }
};

/**
 * one pass
 */
class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> vec;
        ListNode* origin = head;
        while(head != NULL){
            vec.push_back(head);
            head = head->next;
        }
        int length = vec.size();
        if(length == n)
            return origin->next;
        else{
            ListNode* parent = vec[length-n-1];
            ListNode* child = vec[length-n];
            parent->next = child->next;
            return origin;
        }
    }
};
int main(int argv, char *argv[]){
    
    return 0;
}
