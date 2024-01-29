class MyQueue {
public:
    stack<int>st1;
    stack<int>st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        // it is like 
        // pehle org stack ko khali kar le 
        // so that last elem end me aa jaye
        while(!st1.empty()){
            int top=st1.top();
            st1.pop();
            st2.push(top);
        }
        
        st1.push(x); // 
        
        while(!st2.empty()){
            int top=st2.top();
            st2.pop();
            st1.push(top);
        }
    }
    
    int pop() {
        if(!st1.empty()){
            int top=st1.top();
            st1.pop();
            return top;
        }
        
        return -1;
    }
    
    int peek() {
        
        if(!st1.empty()){
            int top=st1.top();
            return top;
        }
        
        return -1;
        
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */