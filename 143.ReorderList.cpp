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
        int count = 0;
        while(head!= NULL){
            count++;
            head = head->next;
        }
        return count;
    }
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        queue<ListNode*> q;
        if(head == NULL || head->next==NULL)
            return;
        ListNode* node = head;
        int len = length(head);
        int count = 0;
        while(count++ < len/2){
            q.push(node);
            node = node->next;
        }
        count--;
        while(count++ < len){
            s.push(node);
            node = node->next;
        }
        q.pop();
        node = head;
        while(!(s.empty()&&q.empty())){
            cout << node->val << endl;
            if(!s.empty()){
                node->next = s.top();
                s.pop();
                node = node->next;
            }
            if(!q.empty()){
                node->next = q.front();
                q.pop();
                node = node->next;
            }
        }
        node->next = NULL;
    }
};
