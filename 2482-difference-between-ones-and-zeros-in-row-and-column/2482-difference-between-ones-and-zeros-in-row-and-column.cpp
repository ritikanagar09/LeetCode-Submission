class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        
        // first cal for 1 row and 1 col 
        
        
        // store colm wise
        
        for(int j=0;j<m;j++){ // colm pe iterate 
            // ynha par row wise check kar va
           int oCol=0;
           int zCol=0;
            for(int i=0;i<n;i++){// row
                if(grid[i][j]==0){ //  colm fixed h row is changing 
                    zCol++;
                }
                
                if(grid[i][j]==1){
                    oCol++;
                }
                
                
            }
            
            for(int i=0;i<n;i++){
                ans[i][j]=(oCol -zCol);
            }   
        }
        
        
        
        for(int i=0;i<n;i++){ // colm pe iterate 
            // ynha par row wise check kar va
           int oRow=0;
           int zRow=0;
            for(int j=0;j<m;j++){// row
                if(grid[i][j]==0){ //  colm fixed h row is changing 
                    zRow++;
                }
                
                if(grid[i][j]==1){
                    oRow++;
                }
                
                
            }
            
            for(int j=0;j<m;j++){
                int x=(oRow-zRow);
                int y=ans[i][j];
                // cout<<x<<" "<<y<<endl;
                ans[i][j]=x+y;  
            }   
        }
        
       
        
        return ans;
    }
};