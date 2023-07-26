class Solution {
public:
    void dfs(int x, int y,vector<vector<char>>& grid, vector<vector<int>>& vis,int n,int m ){
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]=='0' || vis[x][y]){
            return;
        }
        
        vis[x][y]=1;
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
         for(int i=0;i<4;i++){
             int nx=x+dx[i];
             int ny=y+dy[i];
             
             // if(grid[nx][ny]=='1' && !vis[nx][ny]){
                 dfs(nx,ny,grid,vis,n,m);
             // }
         }                                        
                                                 
                                                 
                                                 
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,grid,vis,n,m);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};