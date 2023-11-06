class SeatManager {
public:
    // we will use pq for unreserved seats 
    priority_queue <int,vector<int>,greater<int>>pq;
    SeatManager(int n) {
        
        // ishse bhi bacha jaa skta h kya 
        for(int i=1;i<=n;i++){
            pq.push(i);
        }
    }
    
    int reserve() {
        int top=pq.top();
        pq.pop();
        return top; // this seat have been reserved 
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */