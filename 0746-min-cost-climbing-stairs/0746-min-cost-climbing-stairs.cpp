class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        
        vector<int>dp(n+2,0);
        
        for(int i=n-1; i>=0;i--){
            int a=cost[i]+dp[i+1];
            int b=cost[i]+dp[i+2];
            dp[i]=min(a,b);
        }
        
        return min(dp[0],dp[1]);
    }
};