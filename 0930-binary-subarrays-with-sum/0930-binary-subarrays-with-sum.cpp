class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        
        map<int,int>mpp; // sum, count
        
        int curr_sum=0;
        mpp[0]=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            curr_sum+=nums[i];
            if(mpp.find(curr_sum - goal) != mpp.end()){
                cnt+= mpp[curr_sum - goal];
            }
            
            mpp[curr_sum]++;
            
        }
        
        return cnt;
    }
};