class Solution {
public:
    int pivotInteger(int n) {
        
        if(n <=1){
            return n;
        }
        
        int sum=n*(n+1)/2;
        
        for(int i=1;i<n;i++){
            int psum=i*(i+1)/2;
            int ssum=sum-psum+i;
            
            if(psum==ssum){
                return i;
            }
        }
        
        return -1;
    }
};