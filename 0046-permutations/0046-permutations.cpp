class Solution {
public:
    
    
    void solve(int indx, vector<int>&nums, vector<int>&path, vector<vector<int>>&res, int n){
        if(indx >= n){
            res.push_back(nums);
            return;
        }
        
        
        
        for(int i=indx;i<nums.size();i++){
            
            swap(nums[indx],nums[i]);
            // path.push_back(nums[i]);
            solve(indx+1,nums,path,res,n);
            swap(nums[indx],nums[i]);
            // path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        vector<int>path;
        solve(0,nums,path,res,n);
        return res;
        
    }
};