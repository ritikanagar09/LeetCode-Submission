class Solution {
public:
    int n;
    int solve(int indx, int buy, vector<int>& prices,vector<vector<int>>&dp){
        if(indx==n){
            return 0;
        }
        
        if(dp[indx][buy]!=-1){
            return dp[indx][buy];
        }
        
        int profit=0;
        if(buy){
            int buykaro=-prices[indx]+solve(indx+1,0,prices,dp);
            int skipkaro=0+solve(indx+1,1,prices,dp);
            profit=max(buykaro,skipkaro);
        }else{
            int sellkaro=prices[indx]+solve(indx+1,1,prices,dp);
            int skipkaro=0+solve(indx+1,0,prices,dp);
            profit=max(sellkaro,skipkaro);
        }
        
        return dp[indx][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        
        vector<vector<int>>dp(n+1, vector<int>(2,0));
        // return solve(0,1 ,prices,dp);
        
        for(int indx=n-1;indx>=0;indx--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    int buykaro=-prices[indx]+dp[indx+1][0];
                    int skipkaro=0+dp[indx+1][1];
                    profit=max(buykaro,skipkaro);
                }else{
                    int sellkaro=prices[indx]+dp[indx+1][1];
                    int skipkaro=0+dp[indx+1][0];
                    profit=max(sellkaro,skipkaro);
                }
                
            dp[indx][buy]=profit;
            }
            
        }
        
        return dp[0][1];
    }
};