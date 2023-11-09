class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int cnt=0; queue<pair<int,int>>q;
        vector<vector<int>>vis=grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]!=0){
                    cnt++; // we want to cal only 1 and 2 
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                    
                }
            }
        }
        
        int time=0; 
        int tot=0; 
        while(!q.empty()){
            // timely I'll be using the queue 
            // time++; 
            int size =q.size();
            tot+=size;
            while(size--){
                int x=q.front().first;
                int y=q.front().second; 
                q.pop();
                
                // now I'll be visiting the new node or adjacent nodes from here 
                int dx[]={-1,1,0,0};
                int dy[]={0,0,-1,1};
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                     // ynha par we are just claming ki it has oriogonal colr and it is yet not be 
                    // the sam ecolor it has achieved 
                    if(nx>=0 && ny>=0 && nx<n & ny<m && grid[nx][ny]==1 && vis[nx][ny]!=2){
                        q.push({nx,ny});
                        vis[nx][ny]=2;
                    }
                }
            }
            
            if(!q.empty()){
                time++;
            }
        }
        
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(vis[i][j]==1){
        //             return -1;
        //         }
        //     }
        // }
        
        if(tot !=cnt){
            return -1;
        }
        
        return time;
    }
};