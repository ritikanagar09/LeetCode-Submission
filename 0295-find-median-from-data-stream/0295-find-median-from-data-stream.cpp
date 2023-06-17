class MedianFinder {
public:
    priority_queue<double>max_heap;
    
    priority_queue<double,vector<double>,greater<double>>min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_heap.empty() && min_heap.empty())
        {
            max_heap.push(num);
        }
        else if(!max_heap.empty() && num <= max_heap.top())// left part 
        {
            max_heap.push(num);
        }else{
            min_heap.push(num);
        }
        
        
        // ab push krne k baad we are managing both the heaps 
        int size=max_heap.size() - min_heap.size();
        if(abs(size) > 1){// matlab naa hi odd ke liye kaam karegi naa hi even k liye 
            if(max_heap.size() > min_heap.size()){
                min_heap.push(max_heap.top());
                max_heap.pop();
            }else{
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
    }
    
    double findMedian() {
        
        // either even hoga yaa odd hoga 
        
        if(max_heap.size()==min_heap.size()){ // even case 
            double median= (max_heap.top()+min_heap.top())/2.0;
            
            return median;
        }else {
            if(max_heap.size() > min_heap.size()){
                
                return max_heap.top();
            }else{
                return min_heap.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */