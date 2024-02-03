class Solution {
public:
    
    
    int solve(int i, vector<int>& arr, int& k, vector<int>&dp){
        if(i >= arr.size()){
            return 0;
        }
        
        if(dp[i] !=-1){
            return dp[i];
        }
        int curr_max=-1;
        
        // traverse over the array in the group of size equals to k 
        // or less than k 
        int res=0;
        
        
        for(int j=i;j<arr.size() && j-i+1 <=k;j++){
            curr_max=max(curr_max,arr[j]);
            res=max(res, curr_max * (j-i+1) + solve(j+1,arr,k,dp));
        }
        
        return dp[i]=res;
        
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return solve(0,arr,k,dp);
        
    }
};