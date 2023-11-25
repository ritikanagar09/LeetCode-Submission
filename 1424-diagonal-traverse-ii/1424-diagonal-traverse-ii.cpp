class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int>ans;
        int n=nums.size();
        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            int size=nums[i].size();
            for(int j=0;j<size;j++){
                int sum=i+j;
                sum=n-sum;
                int row=i;
                int val=nums[i][j];
                pq.push({sum,{row,val}});
            }
        }
        
        while(!pq.empty()){
            int val=pq.top().second.second;
            pq.pop();
            ans.push_back(val);
        }
        
        return ans;
        
        
    }
};