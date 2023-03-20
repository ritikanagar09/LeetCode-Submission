class Solution {
public:
    
    int solve(int i, vector<int>&nums, bool flag, vector<int>&dp)
    {
        
        
        if(i>=nums.size()-1 && flag==true){
            return 0;
        }    
        
        if(i>=nums.size() && flag==false){
            return 0;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        
        int take =nums[i]+solve(i+2,nums,flag,dp);
        
        int nottake=0+solve(i+1,nums,flag,dp);
        
        return dp[i]=max(take,nottake);
    }
    
    
    int rob(vector<int>& nums) {
        
        if(nums.size()==1){
            return nums[0];
        }
        
        vector<int>dp(nums.size(),-1);
        int take=solve(0,nums,true,dp);
        vector<int>dp1(nums.size(),-1);
        int nottake=solve(1,nums,false,dp1);
        
        return max(take,nottake);
    }
};