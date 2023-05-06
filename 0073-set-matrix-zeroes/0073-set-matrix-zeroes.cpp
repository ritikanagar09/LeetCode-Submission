class Solution {
public:
    
    int m,n;
    void solve(vector<vector<int>>& matrix, int r,int c){
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==r || j==c){
                    matrix[i][j]=0;
                }
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> nmat=matrix;
        m=matrix.size();
        n=matrix[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    solve(nmat,i,j);
                }
            }
        }
        
        matrix=nmat;
    }
};