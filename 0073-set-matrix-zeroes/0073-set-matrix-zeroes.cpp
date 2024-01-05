class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        // store wherever 0 has been stored 
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)
                    v.push_back({i,j});
            }
        }
        
        for(auto it:v){
            int x=it.first;// row
            int y=it.second;// colm
            for(int i=0;i<n;i++ ){
                mat[i][y]=0;
            }
            
            for(int i=0;i<m;i++ ){
                mat[x][i]=0;
            }
        }
    }
};