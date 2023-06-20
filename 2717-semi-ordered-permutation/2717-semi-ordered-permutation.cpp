class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        
        int n=nums.size();
        
        
        if(nums[0]==1 && nums[n-1]==n){
            return 0;
        }
        
        //
        int indx1=0;
        int indxn=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                indx1=i;
            }
        }
        
        int cnt=0;
        while(indx1 > 0){
            swap(nums[indx1],nums[indx1-1]);
            indx1--;
            cnt++;
        }
        
        
        for(int i=0;i<n;i++){
            if(nums[i]==n){
                indxn=i;
            }
        }
        
        while(indxn <= n-2 ){
            swap(nums[indxn],nums[indxn+1]);
            indxn++;
            cnt++;
        }
        
        return cnt;
        
        
        
        
        
        
        
        
    }
};