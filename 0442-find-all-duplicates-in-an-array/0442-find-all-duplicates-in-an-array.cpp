class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            
            
            int indx=abs(nums[i]);
            int c=nums[indx-1];
            nums[indx -1]=-c;
            
            if(nums[indx -1] > 0){
                ans.push_back(indx);
            }
        }
        
        return ans;
    }
};