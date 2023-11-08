class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        
        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    flag=true;
                }
            }
        }
        
        if(!flag){
            return 0;
        }
        
        vector<vector<int>>vis=grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    // back gya ye bhi toh visit ho gye h naa
                    vis[i][j]=2;
                }else{
                    vis[i][j]=0;
                }
            }
        }
        
        
        int cnt=-1;
        while(!q.empty()){
            int size=q.size();
            
            while(size--){
                pair<int,int> front=q.front();
                int x=front.first;
                int y=front.second;
                q.pop();
                // vis[x][y]=-1;
                int dx[]={1,-1,0,0};
                int dy[]={0,0,1,-1};
                
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    
                    if(nx>=0 && nx<n && ny>=0 && ny<m && 
                      grid[nx][ny]==1 && vis[nx][ny]!=2){
                        vis[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
                
                
            }
            
            cnt++;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return cnt;
    }
};