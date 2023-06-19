class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        
        // 2 cheeze dhyaan rkhni h isme 
        
        // 1: out of range ko bahar nikal do  -> from front
        // 2: muhse or current element se koi kam h toh ushe bahar nikal do -> from back 
        
        
        // deque have been maintained in such a way that the only desired or usefull elemnet 
        // which will heps in having answer will be there in our dequeue 
        deque<int>dq;
        
        
        vector<int>res;
        
        for(int i=0;i<nums.size();i++){
            
            
            // 1 step
            
            if(!dq.empty() && (i-dq.front())==k){
                dq.pop_front(); // sirf ek element hoga --> ek baari mein 
            }
            
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back(); // tumahra raja aa gya h ...ab tum bacho ki jarurut nhi h
            }
            
            dq.push_back(i);
            
            // daalna k window maintain hone k baad hi karnege 
            
            if(i >= k-1){
                res.push_back(nums[dq.front()]);
            }

            
            
        }
        
        return res;
        
        
    }
};