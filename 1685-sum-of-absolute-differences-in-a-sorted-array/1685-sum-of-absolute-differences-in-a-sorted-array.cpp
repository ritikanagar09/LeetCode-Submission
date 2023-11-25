class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int presum=0;
        int totsum=0;
        for(auto it:nums){
            totsum+=it;
        }
        
        int n=nums.size();
        vector<int>ans(n);
        
        for(int i=0;i<n;i++){
            int pre=i;
            int succsum=totsum-presum-nums[i];
            int succ=n-i-1;
            int sum=abs(presum - nums[i]*pre)+abs(succsum-nums[i]*succ);
            presum+=nums[i];
            ans[i]=sum;
            
        }
        
        return ans;
    }
};