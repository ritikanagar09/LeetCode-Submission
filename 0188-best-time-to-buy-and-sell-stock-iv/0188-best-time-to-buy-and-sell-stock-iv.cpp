class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
        
        for(int indx=n-1;indx>=0;indx--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=k;limit++){
                    int profit=0;
                    if(buy){
                        int buykaro=-prices[indx]+dp[indx+1][0][limit];
                        int skip=0+dp[indx+1][1][limit];
                        profit=max(buykaro,skip);
                    }else{
                        int sell =prices[indx]+dp[indx+1][1][limit-1];
                        int skip=0+dp[indx+1][0][limit];
                        profit=max(sell,skip);
                    }

                    dp[indx][buy][limit]= profit;
                }
            }
        }
        
        return dp[0][1][k];
    }
};