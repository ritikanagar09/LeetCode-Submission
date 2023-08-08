class Solution {
public:
    
    int solve(int indx, int tar,vector<int>& nums){
        
        if(tar==0 && indx<0){
            return 1;
        }
        if(indx<0){
            return 0;
        }
        
//         if(tar==0){
//             return 1;
//         }
        
//         if(indx< 0 || tar<0){
//             return 0;
//         }
        
        
        int take=0;
        if(nums[indx] <= tar){
            take=solve(indx-1,tar-nums[indx],nums);
        }
        
        int nottake=solve(indx-1,tar,nums);
        
        return take+nottake;
    }
    
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        int tar=(sum-target)/2;
        
        if((sum-target) < 0 || (sum-target)%2 != 0){
            // cout<<"//"<<endl;
            return 0;
        }
        return solve(n-1,tar,nums);
        
    }
};