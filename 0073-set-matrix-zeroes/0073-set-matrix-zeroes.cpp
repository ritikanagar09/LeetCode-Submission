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
                    v.push_back({i,j});
                }
            }
        }
        
        for(auto el:v){
            int r=el.first;
            int c=el.second;
            cout<<r<<" "<<c<<endl;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i==r || j==c){
                        matrix[i][j]=0;
                    }
                }
            }
        }
        
       
    }
};