class Solution {
public:
    int kadane(vector<int>& nums){
        int sum=0;
        int maxi=nums[0];
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(maxi,sum);
            
            if(sum<0){
                sum=0;
            }
        }
        
        return maxi;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int sum1=kadane(nums);
        
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            nums[i]*=-1;
        }
        
        int sum2=kadane(nums);
        
        if(total+sum2==0)return sum1;
        return max(sum1,total+sum2);
    }
};