class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto i:nums){
            mpp[i]++;
        }
        
        priority_queue<pair<int,int>>pq;
        for(auto i:mpp){
            pq.push({i.second,i.first});
            
        }
        
        vector<int>ans;
        while(k--){
            pair<int,int>p=pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
       
        
        
        
        
        
        return ans;
        
       
    }
};