class Solution {
public:
    int m, n;
    void dfs(int i, int j ,vector<vector<char>>& grid ){
        
        // base case ki aisi koi reuiremnt nhi h
        // par kya karoge agar matrix se hi bahar chla gya 
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!='1'){
            return ;
        }
        //  sabse pehle aa kar visit krte h kisi bhi node ko
        grid[i][j]='2';
        
        // now visit you adjacent nodes
        
        // uske liye call lagwa do ..simple
        
        dfs(i,j+1,grid);
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){// ynha par vo visited vali condition bhi check ho ja rhi h 
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        
        return ans;
            
    }
};