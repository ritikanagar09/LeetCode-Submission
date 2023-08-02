class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int left=0;
        int right=0;
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        while(right<nums.size()){
            pq.push({nums[right],right});
            
            if(right- left + 1 >=k){
                
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