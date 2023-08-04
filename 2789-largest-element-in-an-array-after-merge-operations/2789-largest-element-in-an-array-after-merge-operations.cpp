class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n=nums.size();
        
        long long sum=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<=sum){
                sum+=nums[i];
            }else{
                sum=nums[i];
            }
        }
        
        return sum;
        
    }
};