class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>>q;
        
        //saaare 1 ko dalwado queue ke ander
        //i.e all lands 
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
        vector<vector<int>>visited=grid;
        
        vector<pair<int,int>>directions={{0,1},{1,0},{-1,0},{0,-1}};
        int dist=-1;
        while(!q.empty()){
            int size=q.size();
            
            while(size--){
                auto [x,y]=q.front();
                q.pop();
                for(auto [dx,dy]: directions){
                    int i=x+dx;
                    int j=y+dy;
                    
                    if(i>=0 && i<n && j>=0 && j<m && visited[i][j]==0){
                        visited[i][j]=1;
                        q.push({i,j});
                    }
                }
            }
            
            dist++;//came to the next level
        }
        
        return dist;
    }
};