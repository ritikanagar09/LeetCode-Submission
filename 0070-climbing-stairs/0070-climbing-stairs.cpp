class Solution {
public:
    
    int solve(int n){
        
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        
        
        
        return solve(n-1)+solve(n-2);
    }
    
    int mem(int n, vector<int>&dp){
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        
        if(dp[n]!=-1){
            return  dp[n];
        }
        
        return dp[n]=mem(n-1,dp)+mem(n-2,dp);
    }
    int climbStairs(int n) {
        
        // vector<int>dp(n+1,-1);
        // return mem(n,dp);
        
        vector<int>dp(n+1,0);
        
        dp[0]=1;
        dp[1]=1;// if n ki value 1 h
        
        for(int i=2;i<=n;i++){// we are taking every case for value of n 
            
            dp[i]=dp[i-1]+dp[i-2];
        }
        
        return dp[n];
        
    }
};