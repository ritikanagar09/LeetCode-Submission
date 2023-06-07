class Solution {
public:
    int solve(int i, int j,string str1, string str2, vector<vector<int>>&dp ){
        if(i==0 || j==0){
            return 0;
        }
        
        // match or not match 
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(str1[i-1]==str2[j-1]){
            return dp[i][j]=1+solve(i-1,j-1, str1,str2,dp);
        }
        
        return dp[i][j]=max(solve(i-1,j,str1,str2,dp),solve(i,j-1,str1,str2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int m=text1.size();
        int n=text2.size();
        
        // we do memoisation bcoz we have are having overlapping subproblems 
        
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // return solve(m,n,text1,text2,dp);
//         
        string str1=text1;
        string str2=text2;
        vector<vector<int>>dp(1000+1,vector<int>(1000+1,0));
        
//         int dp[1000 + 1][1000 + 1];
        
//         for (int i = 0; i < m + 1; i++) {
//             for (int j = 0; j < n + 1; j++) {
//                if (i == 0 || j == 0) {
//                    dp[i][j] = 0;
//                } 
//             }
//         }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }

                
            }
        }
        
        return dp[m][n];
        
    }
};