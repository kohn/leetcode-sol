class Stack {
public:
    queue<int> q1;
    queue<int> q2;
    
    queue<int> *q;
    queue<int> *q_bak;
    
    // Push element x onto stack.
    void push(int x) {
        q_bak->push(x);
        while(!q->empty()){
            q_bak->push(q->front());
            q->pop();
        }
        queue<int> *tmp = q;
        q = q_bak;
        q_bak = tmp;
    }

    // Removes the element on top of the stack.
    void pop() {
        q->pop();
    }

    // Get the top element.
    int top() {
        return q->front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q->empty();
    }
    
    Stack(){
        q = &q1;
        q_bak = &q2;
    }
};
