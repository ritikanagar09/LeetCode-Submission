class Solution {
public:
    int m, n;
    bool dfs(vector<vector<int>> &grid, int r, int c) {
        
        if(r < 0 || r >= m || c < 0 || c >= n)
            return false; //Not closed
        
        if(grid[r][c] == 1)
            return true; //closed here
        
        grid[r][c] = 1;
        
        bool left  = dfs(grid, r, c-1);
        bool right = dfs(grid, r, c+1);
        bool up    = dfs(grid, r-1, c);
        bool down  = dfs(grid, r+1, c);
        
        return left && right && up && down;
        
    }
//     int dfs(int i,int j, int m ,int n,vector<vector<int>>& grid ){
        
//         if(i>=m || j>=n || i<0 || j<0){
//             return 0;
//         }
        
//         if(grid[i][j]==1){
//             return 1;
//         }
        
//         grid[i][j]=1;
        
//         int l=dfs(i,j-1,m,n,grid);
//         int r=dfs(i,j+1,m,n,grid);
//         int u=dfs(i-1,j,m,n,grid);
//         int d=dfs(i+1,j,m,n,grid);
        
//         return l && u && r && u && d;
            
        
//     }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    // int cnt=dfs(i,j,m,n,grid);
                    ans+=dfs(grid,i,j);
                    // ans+=cnt;
                    // cout<<cnt<<endl;
                    
                }
                
            }
        }
        
        return ans;
    }
}; 