class Solution {
public:
    int countOdds(int low, int high) {
        int k=high-low+1;
        if(k%2==0){
            return k/2;
        }else{
            if(high%2==0){
                return k/2;
            }else{
                return k/2+1;
            }
        }
    }
};