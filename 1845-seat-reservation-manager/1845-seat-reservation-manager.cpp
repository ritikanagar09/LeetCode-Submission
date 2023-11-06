class SeatManager {
public:
    // we will use pq for unreserved seats 
    priority_queue <int,vector<int>,greater<int>>pq;
    int seat_marker=1;
    SeatManager(int n) {
        
        // ishse bhi bacha jaa skta h kya 
        
    }
    
    int reserve() {
        
        if(!pq.empty()){
            int top=pq.top();
            pq.pop();
            return top; // this seat have been reserved 
        }
        
        int seat=seat_marker;
        seat_marker++;
        return seat;
        
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