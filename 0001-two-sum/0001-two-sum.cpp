class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        // sort(nums.begin(),nums.end());
        map<int,int>mpp;
        
        for(int i=0;i<n;i++){
            
            
            if(mpp.find(target-nums[i])!=mpp.end()){
                vector<int>temp={mpp[target-nums[i]],i};
                return temp;
            }
            mpp[nums[i]]=i;
        }
        
        return {};
    }
};