class Solution {
public:
  
    int solve(vector<int>&nums, int i, int sum,vector<vector<int>>&dp) 
    {   
       if(i==0){
            if(sum==0 && nums[0]==0){
                return 2;
            }else if(sum==0 || nums[0]==sum){
                return 1;
            }else{
                return 0;
            }
            
        }
        
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        
        int a=solve(nums, i-1, sum,dp);// exclude
        int b=0;
        if(nums[i]<=sum){
            b = solve(nums, i-1, sum-nums[i],dp);
        }
        
        
        return dp[i][sum]= a+b; 
        
       
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum= accumulate(nums.begin(), nums.end(),0);
        
        int W=(sum-target)/2;
        
        if(sum<target || (sum-target) % 2!=0){
            return 0;
        }
        
        vector<vector<int>>dp(nums.size(),vector<int>(W+1,-1));
        return solve(nums, nums.size()-1, W , dp);//-100
    }
};