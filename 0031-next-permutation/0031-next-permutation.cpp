class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        
        int indx=-1;
        // finding break point 
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                indx=i;
                break;
            }
        }
        if(indx < 0){
            // no break point found
            reverse(nums.begin(),nums.end());
            return;
        }
        
        cout<<"//"<<endl;
        for(int i=n-1;i>=0;i--){
            // someone greater than A but smaller 
            if(nums[i]>nums[indx]){
                swap(nums[i],nums[indx]);
                break;
            }
        }
        
        reverse(nums.begin()+indx+1,nums.end());
    }
};