class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int>res;
        deque<int>dq;
        int n=nums.size();
        for(int i=0;i<n;i++){
           
                if(!dq.empty()&&(i-dq.front()-k==0)){
                    dq.pop_front();
                }
                while(!dq.empty() && nums[dq.back()]<nums[i]){
                    // dq.pop_front();
                    dq.pop_back();
                }
                
                
                
                dq.push_back(i);
            
            
            // ek case or handle krna h 
            // ki out of boundary wala case 
            
            
            if(i>=k-1){
                res.push_back(nums[dq.front()]);
            }
        }
    
            
        
        
        return res;
    }
};