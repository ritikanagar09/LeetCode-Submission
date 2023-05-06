class Solution {
public:
    int m,n;
    
    void setZeroes(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        
        vector<pair<int,int>>v;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<m;k++){
                        for(int b=0;b<n;b++){
                            if(matrix[k][b]!=0 && (k==i ||b==j)){
                                matrix[k][b]=-1e8;
                            }
                        }
                    }
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(matrix[i][j]==-1e8){
                   matrix[i][j]=0;
               } 
            }
        }
        
        
        
        
       
    }
};