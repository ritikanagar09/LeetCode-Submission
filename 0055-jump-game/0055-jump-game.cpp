class Solution {
public:
    bool solve(int i,vector<int>& nums,vector<int>&dp  ){
        
        
        if(i==nums.size()-1){
            
            return true;
        }
        if(i>nums.size()-1){
            
            return false;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int k=1;k<=nums[i];k++){
          
            if(solve(i+k,nums,dp)){
                return dp[i]=true;
            }  
        }
       
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        
        vector<int>dp(nums.size(),-1);
        return solve(0,nums,dp);
    }
};