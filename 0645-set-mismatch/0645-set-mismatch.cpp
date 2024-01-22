class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans;
        
        vector<int>vis(n+1,0);
        
        for(int i=0;i<n;i++){
            if(vis[nums[i]]==1){
                ans.push_back(nums[i]);
            }
            
            vis[nums[i]]=1;
        }
        
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                ans.push_back(i);
            }
        }
        
        return ans;
        // [2,3,3,4,5,6];
    }
};