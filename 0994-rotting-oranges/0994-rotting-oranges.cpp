class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        bool flag=true;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    flag=false;
                    
                }
            }
        }
        
        if(flag){
            return 0;
        }
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>vis(m, vector<int>(n,0));
        int time=-1;
        while(!q.empty()){
            int size=q.size();
            
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                
                q.pop();
                
                
                int dx[]={-1,0,1,0};
                int dy[]={0,1,0,-1};
                
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
            
            time++;
        }
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        
        return time;
    }
};