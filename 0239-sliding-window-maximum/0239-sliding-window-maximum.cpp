class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        
        deque<int>dq;
        vector<int>ans;
        // we are storing indexes in deque
        for(int i=0;i<n;i++){
            
            // remove out of bounds 
            
            if(!dq.empty() && dq.front()==i-k){
                dq.pop_front();
            }
            
            // we need to store only maximum elem
            // store which are smaller than it 
            // we have stored elem in decreasing order 
            // toh sabse pehle piche remove krna 
            // shuru karo
            
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            
            
            dq.push_back(i);
            
            // we start taking elemnts from
            
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        
        return ans;
    }
};