class Solution {
public:
    
    int solve(vector<int>& nums, int goal){
        int n=nums.size();
        
        
        int cnt=0;
        int l=0;
        int r=0;
        
        int sum=0;
        while( r < n){
            
            sum+=nums[r];
            while(l <=r && sum > goal)
                    sum-=nums[l++];
                   
            cnt+=r-l+1;
            
            r++;
            
        }
        
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve(nums,goal-1);
    }
};