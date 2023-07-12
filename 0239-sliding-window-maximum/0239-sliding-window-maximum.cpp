class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        
        int n=nums.size();
        
        int right=0;
        int left=0;
        priority_queue<pair<int,int>>pq;
        
        vector<int>ans;
        while(right < n){
            
            pq.push({nums[right],right});
            if(right-left+1>=k){
                while(pq.top().second < left){
                    pq.pop();
                }
                
                ans.push_back(pq.top().first);
                left++;
                
            }
            
            right++;
        }
        
        return ans;
        
        
    }
};