class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        // to store where are in the orw and colm zero is coming 
        vector<int>row(n,1);
        vector<int>colm(m,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    row[i]=0;
                    colm[j]=0;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i]==0 || colm[j]==0){
                    mat[i][j]=0;
                }
            }
        }
        
    }
};