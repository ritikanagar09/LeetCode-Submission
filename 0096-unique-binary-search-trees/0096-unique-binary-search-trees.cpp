class Solution {
public:
    int numTrees(int n) {
        
        if(n==0 || n==1){
            return 1;
        } 
    
        int ways=0;
        
        // ye saari ki saari root nodes bna di h humne 
        for(int i=1;i<=n;i++){
            ways+=numTrees(i-1)*numTrees(n-i);
        }
        
        return ways;
    }
};