class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<int>sumR(n,0);
        vector<int>sumC(m,0);
        
        int cnt= 0;
        
        
        for(int i=0;i<n;i++){
            int sum =0 ;
            for(int j=0 ;j<m;j++){
                sum+=mat[i][j];
            }
            
            sumR[i]=sum;
        }
        
        for(int j=0;j<m;j++){
            int sum =0 ;
            for(int i=0 ;i<n;i++){
                sum+=mat[i][j];
            }
            
            sumC[j]=sum;
        }
        
        for(int i=0 ;i<n;i++){
            for(int j=0 ;j <m;j++){
                
                if(mat[i][j]==1 && sumR[i]==1 && sumC[j]==1){
                    cnt++;
                    cout<<i<<" "<<j<<" "<<sumR[i]<< " "<< sumC[j]<<endl;
                }
            }
        }
        
        
        
        return cnt;
    }
};