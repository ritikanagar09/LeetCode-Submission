class Solution {
public:

int solve(vector<int>& arr,int n,int i,int prev,vector<vector<int>>&dp){
    if(i>=n){
        return 0;
    }
    
    if(dp[i][prev+1]!=-1){
        return dp[i][prev+1];
    }

    int a=0;
    if(prev==-1 || arr[i]>arr[prev]){
        a= 1+solve(arr,n,i+1,i,dp);
    }

    int b=solve(arr,n,i+1,prev,dp);
    
    //  if(prev==-1){
    //     return max(a,b);
    //  }
    // else
     return dp[i][prev+1]=max(a,b);
} 

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return solve(nums,n,0,-1,dp);
    }
};