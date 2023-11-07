class Solution {
public:
    int n;
    int m;
    void dfs(int x, int y,vector<vector<char>>& grid, vector<vector<int>>& vis ){
        
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]=='1' && !vis[nx][ny]){
                vis[nx][ny]=1;
                dfs(nx,ny,grid,vis);
            }
            
        }
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
        
        n=grid.size();
        m=grid[0].size();
        
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};