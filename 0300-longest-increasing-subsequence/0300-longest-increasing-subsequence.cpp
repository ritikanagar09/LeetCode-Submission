class Solution {
public:
    
    // striclty increasing array rkhna hai 
    int solve(int indx, int prev, vector<int>&arr, int n, vector<vector<int>>&dp ){
        if(indx >= n){
            return 0;
        }
        if(dp[indx][prev+1] != -1){
            return dp[indx][prev+1];
        }
        // take
        int take=0;
        if(prev==-1 || arr[indx]> arr[prev]){
            take=1+solve(indx+1,indx,arr,n,dp);
        }
        
        int not_take=solve(indx+1,prev,arr,n,dp);
        
        return dp[indx][prev+1]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,n,dp);
    }
};