class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        
        map<int,int>mpp;
        
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        
        int maxi=0;
        for(auto it:mpp){
            maxi=max(maxi,it.second);
        }
        
        vector<vector<int>>ans(maxi);
        
        for(auto it:mpp){
            int m=it.second;
            for(int i=0;i<m;i++){
                ans[i].push_back(it.first);
            }
        }
        
        return ans;
        
        
    }
};