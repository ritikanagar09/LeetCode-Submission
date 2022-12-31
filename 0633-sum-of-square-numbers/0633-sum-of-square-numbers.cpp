class Solution {
public:
    bool judgeSquareSum(int c) {
        int k=sqrt(c);
        
        for(int i=0;i<=k;i++){
            int a=c-i*i;
            
            int low=0;
            int high=k;
            
            while(low<=high){
                int mid=low+(high-low)/2;
                int m=mid*mid;
                if(m>a){
                    high=mid-1;
                    
                }else if(m<a){
                    low=mid+1;
                }else{
                    return true;
                }
            }
        }
        
        return false;
    }
};