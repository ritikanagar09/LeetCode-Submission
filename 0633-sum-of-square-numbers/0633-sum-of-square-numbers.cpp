class Solution {
public:
    bool judgeSquareSum(int c) {
        
        long long low=0;
        long long high=sqrt(c);
        
        while(low<=high){
            
            long long k=(low*low) + (high*high);
            if(k==c){
                return true;
            }else if(k>c){
                high--;
               
            }else if(k<c){
                 low++;
            }
        }
        
         return false;
    }
};