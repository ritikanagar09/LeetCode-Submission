class Solution {
public:
    int n;
    int solve(int indx, int buy, int limit,vector<int>& prices){
        
        if(indx==n || limit==0){
            return 0; // no more profit can be achieved 
        }
        
        int profit=0;
        if(buy){
            int buykaro=-prices[indx]+solve(indx+1,0,limit,prices );
            int skip=0+solve(indx+1,1,limit,prices);
            profit=max(buykaro,skip);
        }else{
            int sell =prices[indx]+solve(indx+1,1,limit-1, prices);
            int skip=0+solve(indx+1,0,limit, prices);
            profit=max(sell,skip);
        }
        
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        // return solve(0,1,2,prices);
        
        // 3d dp 
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        
        for(int indx=n-1;indx>=0;indx--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=2;limit++){
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
        
        return dp[0][1][2];
    }
};