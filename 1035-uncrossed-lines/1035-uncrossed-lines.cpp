class Solution {
public:
    int n,m;
    int solve(int i, int j,vector<int>& nums1, vector<int>& nums2, vector<vector<int>>&dp ){
        if(i>n-1 || j>m-1){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int a=0,b=0;
        if(nums1[i]==nums2[j]){
            a=1+solve(i+1,j+1,nums1,nums2,dp);
        }else{
            int first=solve(i+1,j,nums1,nums2,dp);
            int sec=solve(i,j+1,nums1,nums2,dp);
            
            b=max(first,sec);
        }
        
        return dp[i][j]=max(a,b);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        n=nums1.size();
        m=nums2.size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return solve(0,0,nums1,nums2,dp);
        
    }
};