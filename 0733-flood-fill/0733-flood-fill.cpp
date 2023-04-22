class Solution {
public:
    int m, n;
    void dfs(int i, int j, int colr, int ncolr,vector<vector<int>>& image, vector<vector<int>>&ans, int delx[], int dely[]){
        
        ans[i][j]=ncolr;//color it with new color 
        
        cout<<i<<" "<<j<<endl;
        for(int k=0;k<4;k++){
            int nx=i+delx[k];
            int ny=j+dely[k];
            // ye condition h jo sb kuch smbhaal rhi h 
            
            if(nx>=0 && nx<n && ny>=0 && ny<m && image[nx][ny]==colr && ans[nx][ny]!=ncolr ){
               
                dfs(nx, ny,colr, ncolr,image, ans, delx, dely);
            }
        }
        
        
       
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        
        // see how we will be doing code without even using visited array 
        // bss kuch condition use kar k
        
        n=image.size();
        m=image[0].size();
        
        
        int colr=image[sr][sc];
        
        int delx[]={-1,0,1,0};
        int dely[]={0,1,0,-1};
        dfs(sr,sc,colr,color, image,ans, delx, dely);
        
        return ans;
        
    }
};