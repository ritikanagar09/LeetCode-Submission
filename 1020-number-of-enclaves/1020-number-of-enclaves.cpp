class Solution {
public:
    void dfs(int i , int j ,vector<vector<int>>&vis,vector<vector<int>>& grid,int& ans,bool &a ){
         int n = grid.size();
        int m = grid[0].size();
        if( i==0 || j==0 ||i==n-1 || j==m-1){
            a = false;
        }
        vis[i][j]=1;
        ans++;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,-1,0,1};
        for(int ii =0; ii<4 ; ii++){
            int xx = i + dx[ii];
            int yy = j + dy[ii];
            if(xx>=0 && yy>=0 && xx<n && yy<m && grid[xx][yy]==1 && vis[xx][yy]==-1){
                dfs(xx,yy,vis,grid,ans,a);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt =0;
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i =0; i<n ; i++){
            for(int j =0; j<m ; j++){
                if(vis[i][j]==-1 && grid[i][j]==1){
                    int ans =0;
                    bool a = true;
                    dfs(i,j,vis,grid, ans,a );
                    if(a){
                        cnt +=ans;
                    }
                }
            }
        }
        return cnt;
    }
};