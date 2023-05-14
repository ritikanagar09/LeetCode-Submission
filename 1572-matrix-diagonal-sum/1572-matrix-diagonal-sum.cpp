class Solution {
public:
    int diagonalSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        int sum=0;
        
        for(int i=0;i<n;i++){
            int k=matrix[i][i]+matrix[i][n-i-1];
            sum+=k;
        }
        
        if(n%2)
            sum-=matrix[n/2][n/2];
        
        return sum;
        
        
        
        
        
    }
};