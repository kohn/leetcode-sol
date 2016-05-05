#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head){
    ListNode* it = head;
    while(it != NULL){
        cout<<it->val<<" ";
        it = it->next;
    }
    cout<<endl;
}

struct cmp_smaller{
    bool operator()(ListNode* a, ListNode* b){
        if(a == NULL || b==NULL){
            cout<<"ERROR: "<<endl;
        }
        return a->val > b->val;
    }
};

class Solution {
private:
    void insert_into_list(ListNode* &head, ListNode* &tail, ListNode* node){
        if(head == NULL && tail == NULL){
            head = node;
            tail = node;
        }
        else{
            tail->next = node;
            tail = node;
        }
    }
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp_smaller> q;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        for(auto it=lists.begin(); it!=lists.end(); it++) {
            if(*it != NULL)
                q.push(*it);
        }
        while(!q.empty()){
            ListNode* top = q.top();
            q.pop();
            
            ListNode* next = top->next;
            
            insert_into_list(head, tail, top);
            //printList(head);
            
            if(next != NULL)
                q.push(next);
        }
        return head;
    }
};


int main(int argc, char *argv[])
{
    ListNode* node = new ListNode(1);
    node->next = new ListNode(3);
    node->next->next = new ListNode(5);
    printList(node);
    
    ListNode* node2 = new ListNode(2);
    node2->next = new ListNode(4);
    node2->next->next = new ListNode(6);
    printList(node2);
    
    vector<ListNode*> v;
    v.push_back(node);
    v.push_back(node2);

    vector<ListNode*> v2;
    v2.push_back(NULL);
    Solution s;

    printList(s.mergeKLists(v2));
    return 0;
}
