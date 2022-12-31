class Solution {
public:
    int solve(int i, int j ,int m ,int n, vector<vector<int>>& grid, int cnt, int tot){
        
        // cout<<i<<" "<<j<<endl;
        if(i>=m || j>=n || i<0 || j<0 || grid[i][j]==-1 || grid[i][j]==3){
            // cout<<"//"<<endl;
            return 0;
        }
        
        
        if(grid[i][j]==2){
            if(cnt==tot)
                return 1;
            else
                return 0;
        }
        
        int k=grid[i][j];
        
        
        int u,d,l,r=0;
        grid[i][j]=3;
        cnt++;
        u =solve(i-1,j,m,n,grid,cnt,tot);
        d =solve(i+1,j,m,n,grid,cnt,tot);
        r =solve(i,j+1,m,n,grid,cnt,tot);
        l =solve(i,j-1,m,n,grid,cnt,tot);
        
        
        //backtrack
        grid[i][j]=k;
        
        return u+d+r+l;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        
        int tot=0;
        int l, r;
        vector<vector<int>>vis(m,vector<int>(n,3));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    l=i;
                    r=j;
                }
                
                if(grid[i][j]==1 || grid[i][j]==0){
                    tot++;
                }
            }
        }
        int cnt=0;
        return solve(l,r,m,n,grid,cnt,tot);
    }
};