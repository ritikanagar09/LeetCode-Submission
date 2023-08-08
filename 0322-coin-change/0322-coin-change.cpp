class Solution {
public:
    
    int solve(int indx, int tar,vector<int>& coins, vector<vector<int>>&dp ){
        
        if(tar==0){
            return 0;
        }
        
        if(indx < 0){
            return 1e9;
        }
        
        if(dp[indx][tar]!=-1){
            return dp[indx][tar];
        }
        
        
        int pick=1e9;
        if(coins[indx] <= tar){
            pick=1+solve(indx,tar-coins[indx],coins,dp);
        }
        
        int notpick=solve(indx-1,tar,coins,dp);
        
        return dp[indx][tar]=min(pick,notpick);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        
        
        int n=coins.size()-1;
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=solve(coins.size()-1,amount,coins,dp);
        if(ans==1e9){
            return -1;
        }
        
        return ans;
        
    }
};