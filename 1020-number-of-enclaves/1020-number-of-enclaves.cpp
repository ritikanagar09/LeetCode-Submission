class Solution {
public:
            // ye question is same as no of closed island but have some diffrence 
        // rerefce: -striver graphs
//      toh isme agar koi island bpundar wale island se connected h toh ..voh bhi boundary
//         se bahar walk in kar skta ..and we dont want this 
//         we want only islands jo bahar nhi ja pa rhae hai 
//         toh agar hum boundary wale islands se dfs karu or dekhu agar ishe koi atatch h toh tum hat jao..you will not be counted in answer 
//         bche hue is the answer 
        
    int m, n; 
    
    void dfs(int i, int j,vector<vector<int>>& grid ){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0){
            return;
        }
        
        // bss visit hi toh karna h 
        //jisse boundary wale attach koi bhi island agar h toh ushe final count me nhi rkhna hume 
        
        grid[i][j]=0;
        
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        
        
        // toh boundary walo ko tarverse kate hai sabse pehle 
        // ab ynh aja kar unhe 0 bna de rhae jo boundary wale se attach so that vo
        // final count me naa aaye 
        
        //first row
        for(int j=0;j<n;j++){
            if(grid[0][j]==1)
                dfs(0,j,grid);
        }
        
        //first coloumn
        for(int i=0;i<m;i++){
            if(grid[i][0]==1)
                dfs(i,0,grid);
        }
        
        //last row
        for(int j=0;j<n;j++){
            if(grid[m-1][j]==1)
                dfs(m-1,j,grid);
        }
        
        //last column
        for(int i=0;i<m;i++){
            if(grid[i][n-1]==1)
                dfs(i,n-1,grid);
        }
        
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};