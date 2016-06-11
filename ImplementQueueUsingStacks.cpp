class Queue {
public:
    stack<int> s1;
    stack<int> s2;
    
    void pour(stack<int> &sta1, stack<int> &sta2){
        while(!sta1.empty()){
            sta2.push(sta1.top());
            sta1.pop();
        }
    }
    
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        pour(s1, s2);
        s2.pop();
        pour(s2, s1);
    }

    // Get the front element.
    int peek(void) {
        pour(s1, s2);
        int top = s2.top();
        pour(s2, s1);
        return top;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty();
    }
};
