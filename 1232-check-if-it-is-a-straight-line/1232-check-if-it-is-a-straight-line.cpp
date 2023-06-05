class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        
        int dx=coordinates[1][0]-coordinates[0][0];
        int dy=coordinates[1][1]-coordinates[0][1];
        
        // int slope=dy/dx;
        for(int i=2;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    int ndx=coordinates[j][0]-coordinates[i][0];
                    int ndy=coordinates[j][1]-coordinates[i][1];

                    // int nslope=ndy/ndx;

                    if(dy*ndx!=dx*ndy){
                        return false;
                    }
                }
                
            }
        }
        
        return true;
                              
                              
    }
};