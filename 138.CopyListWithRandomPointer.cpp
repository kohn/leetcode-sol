/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// 用map来保存新老结点的关系, 需要额外空间
// 可以用老链表的每个结点后插入新节点的方式来知道新老结点的关系, 避免map
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        Node* node = head;
        map<Node*, Node*> visited;
        while(node != NULL) {
            Node* newNode = new Node(node->val);
            visited[node] = newNode;
            node = node->next;
        }

        node = head;
        Node* newListHead = NULL;
        Node* newListTail;
        while(node != NULL) {
            if(newListHead == NULL) {
                newListHead = visited[node];
                newListTail = newListHead;
                newListTail->random = visited[node->random];
            } else {
                newListTail->next = visited[node];
                newListTail = newListTail->next;
                newListTail->random = visited[node->random];
            }
            node = node->next;
        }
        return newListHead;
    }
};
