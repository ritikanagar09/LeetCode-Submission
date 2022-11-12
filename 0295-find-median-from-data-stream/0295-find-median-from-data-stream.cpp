class MedianFinder {
public:
    priority_queue<double> max_pq;
    priority_queue<double, vector<double>, greater<double> > min_pq;      
    MedianFinder() {
        
    }
    
    void addNum(int num) {
            if(min_pq.empty() && max_pq.empty()){
                max_pq.push(num);
            } 
            else if(!max_pq.empty() && num <= max_pq.top()){
                max_pq.push(num);
            } 
            else{
                min_pq.push(num);
            }
        
        
        if(abs(max_pq.size() - min_pq.size() > 1)){ 
                if(max_pq.size() > min_pq.size()){
                    min_pq.push(max_pq.top());
                    max_pq.pop();
                } else {
                    max_pq.push(min_pq.top());
                    min_pq.pop();
                }
        }
    }
    
    double findMedian() {
        
        double median;
            

            if(max_pq.size() > min_pq.size()){ 
                median= max_pq.top();
            } else if(max_pq.size() < min_pq.size()){
                median= min_pq.top();
            } else {
                
                if(max_pq.empty()){
                    median=0;
                } else{
                    median = (max_pq.top() + min_pq.top())/2.0;
                }
                
            }
        
         return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */