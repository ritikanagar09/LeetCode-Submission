class Solution {
public:
   int f(int n,vector<int>&dp){
       if(n==0){
           return 0;
       }
       if(dp[n]!=-1){
           return dp[n];
       }
       int ans = INT_MAX;
       for(int i =1  ;i*i<=n ; i++){
           int a = 1 + f(n- i*i,dp);
           ans  = min(a,ans);
       }
       return dp[n]= ans;

   }
    int numSquares(int n) {
        
        int i =1;
        vector<int>dp(n+1,-1);
        int ans  = f(n,dp);
        return ans;

        
    }
};