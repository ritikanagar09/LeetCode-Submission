class MyQueue {
public:
    
     stack<int>s1;
    stack<int>s2;
    MyQueue() {
       
    }
    
    void push(int x) {
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        
        s1.push(x);
        
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        
        // actually elemts are stored in s2 
    }
    
    int pop() {
        if(!s2.empty()){
            int x=s2.top();
            s2.pop();
            return x;
            
        }else{
            return -1;
        }
    }
    
    int peek() {
        if(!s2.empty()){
            return s2.top();
        }else{
            return 0;
        }
    }
    
    bool empty() {
        
        return s2.empty();
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