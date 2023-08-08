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
        
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        
        // return solve(coins.size()-1,amount,coins,dp);
        
        dp[0][0]=1;
        
        for(int i=1; i <=n ;i++){
            dp[i][0]=1;
        }
        
        for(int indx=1;indx<=n;indx++){
            for(int tar=1;tar<=amount;tar++){
                int pick=0;
                if(coins[indx-1]<=tar){
                    pick=dp[indx][tar-coins[indx-1]];
                }

                int notpick=dp[indx-1][tar];
                dp[indx][tar]=pick+notpick;
            }
        }
        
        
        return dp[n][amount];
    }
};