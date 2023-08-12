class Solution {
public:
    
//     int solve(int i, int j,vector<vector<int>>& grid , int m, int n){
        
//         if(i>=m || j>=n || grid[i][j]==1){
//             return 0;
//         }
        
//         if(i==m-1 && j==n-1){
//             return 1;
//         }
        
//         int right=solve(i,j+1,grid,m,n);
//         int down=solve(i+1,j,grid,m,n);
        
//         return right+down;
//     }
    
    int solve(int i, int j,vector<vector<int>>& grid , int m, int n){
        
        if(i<0 || j<0 || grid[i][j]==1){
            return 0;
        }
        
        if(i==0 && j==0){
            return 1;
        }
        
        int right=solve(i,j-1,grid,m,n);
        int down=solve(i-1,j,grid,m,n);
        
        return right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        
        // return solve(0,0,grid,m,n);
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        dp[0][1]=1;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                
                if(grid[i-1][j-1]==0){
                    int right=dp[i][j-1];
                    int down=dp[i-1][j];

                    dp[i][j]=right+down;
                }
                
            }
        }
        
        return dp[m][n];
    }
};