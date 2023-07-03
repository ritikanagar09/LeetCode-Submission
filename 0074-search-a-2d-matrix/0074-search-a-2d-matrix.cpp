class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size();
        int n=mat[0].size();

        for(int i=0;i<m;i++){
            int low=mat[i][0];
            int high=mat[i][n-1];

            if(low<=target && target <=high){
                for(int j=0;j<n;j++){
                    if(mat[i][j]==target){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};