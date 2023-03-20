class Solution {
public:     
    
    int solve(int i, vector<int>&nums, vector<int>&dp){
        if(i>=nums.size()){
            return 0;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        int take =nums[i]+solve(i+2,nums,dp);
        
        int nottake=0+solve(i+1,nums,dp);
        
        return dp[i]= max(take,nottake);
    }
    
    
    int rob(vector<int>& nums) {
        
        
        vector<int>dp(nums.size(),-1);
        return solve(0,nums,dp);
    }
};