class Solution {
public:
    
    int solve(int n){
        
        if(n==0 || n==1){
            return 1;
        } 
        
        
        int ways=0;
        for(int i=1;i<=n;i++){
            ways+=solve(i-1)*solve(n-i);
        }
        
        return ways;
    }
    int numTrees(int n) {
        
        return solve(n);
    }
};