class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,-1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        
        if(q.size()==0 || q.size()== m*n){
            return -1;
        }
        
        
        int cnt=-1;
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
            int size=q.size();
            
            for(int i=0;i<size;i++){
                auto front=q.front();
                int x=front.first;
                int y=front.second;
                
                q.pop();
                
                for(auto it:dir){
                    int dx=it[0];
                    int dy=it[1];
                    
                    if(x+dx >=0 && x+dx <n && y+dy >=0 && y+dy <m && vis[x+dx][y+dy]==-1 && grid[x+dx][y+dy]==0){
                        q.push({x+dx,y+dy});
                        vis[x+dx][y+dy]=1;
                    }
                }
                
                
            }
            
            cnt++;
        }
        
        return cnt;
    }
};