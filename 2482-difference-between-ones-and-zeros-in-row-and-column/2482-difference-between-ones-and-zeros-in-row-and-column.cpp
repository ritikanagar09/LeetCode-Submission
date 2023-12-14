class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        
        vector<int>oRow(n,0);
        
        vector<int>oCol(m,0);
        
        for(int i=0 ;i<n;i++){
            int one=0; 
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    one++; 
                }
            }
            
            oRow[i]=one; 
        }
        
        for(int j=0 ;j<m;j++){
            int one=0; 
            for(int i=0;i<n;i++){
                if(grid[i][j]==1){
                    one++; 
                }
            }
            
            oCol[j]=one; 
        }
        
        
        for(int i=0 ;i<n;i++){
            for(int j=0 ;j<m;j++){
                int zCol=m-oCol[j];
                int zRow=n-oRow[i];
                ans[i][j]=oRow[i]+oCol[j]-zCol-zRow;
            }
        }
        
        return ans;
    }
};