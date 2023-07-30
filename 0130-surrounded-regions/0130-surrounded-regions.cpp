class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        // vector<vector<int>>ans=grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    
                    if(grid[i][j]=='O'){
                        // ans[i][j]=2;
                        vis[i][j]=1;
                        q.push({i,j});
                    }
                    
                    
                }
            }
        }
        
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        
        while(!q.empty()){
            
            int x=q.front().first;
            int y=q.front().second;
            
            q.pop();
            
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && grid[nx][ny]=='O'){
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                    // ans[nx][ny]=2;
                }
            }
            
            
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(!vis[i][j] && grid[i][j]=='O'){
                    grid[i][j]='X';
                }
                    
            }
            
        }
        
    }
};