class MinStack {
public:
    stack<long long>st;
    
    long long mini;
    MinStack() {
        while(st.empty()==false)st.pop();
        mini=INT_MAX;
    }
    
    void push(int val) {
        // long long v=val;
        // if(v>mini){
        //     st.push(v);
        //     // mini=min(mini,v);
        // }else{
        //     long long nval=2*v*1LL-mini;
        //     st.push(nval);
        //     mini=v;
        // }
        
        long long v=val;
        
        if(st.empty()){
            mini=v;
            st.push(v);
        }else{
            cout<<"//"<<endl;
            if(v>mini){
                st.push(v);
            }else{
                cout<<"&&&"<<endl;
                long long nval=2*v*1LL-mini;
                st.push(nval);
                mini=v;
            }
        }
        
        cout<<mini<<" 1"<<endl;
    }
    
    void pop() {
        
        // if(st.top()>mini){
        //     st.pop();
        // }else{
        //     int nval=st.top();
        //     int val=mini;
        //     long long nmini=2*mini*1LL-nval;
        //     mini=nmini;
        //     st.pop();
        // }
        
        long long nval=st.top();
        
        if(nval < mini)
        {
            long long nmini=2*mini*1LL-nval;
            mini=nmini;
        }
        st.pop();
    }
    
    int top() {
        
        long long nval=st.top();
        
        
        
        if(nval<mini){
            return mini;
        }
        
        return nval;
        
        cout<<mini<<" 2"<<endl;
        
    }
    
    int getMin() {
        cout<<mini<<" 3"<<endl;
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */