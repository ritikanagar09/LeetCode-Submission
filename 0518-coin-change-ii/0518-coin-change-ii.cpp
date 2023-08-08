class Solution {
public:
    
    int solve(int indx, int tar,vector<int>& coins,vector<vector<int>>&dp ){
        
        if(tar==0){
            return 1;
        }
        
        if(indx < 0){
            return 0;
        }
        
        if(dp[indx][tar]!=-1){
            return dp[indx][tar];
        }
        
        
        int pick=0;
        if(coins[indx]<=tar){
            pick=solve(indx,tar-coins[indx],coins,dp);
        }
        
        int notpick=solve(indx-1,tar,coins,dp);
        
        return dp[indx][tar]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        
        return solve(coins.size()-1,amount,coins,dp);
    }
};