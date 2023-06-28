class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            mpp[nums[i]]=i;
        }
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            int left=target-nums[i];
            
            if(mpp.find(left)!=mpp.end() && i!=mpp[left]){
                ans.push_back(i);
                ans.push_back(mpp[left]);
                break;
            } 
        }
        
        return ans;
    }
};