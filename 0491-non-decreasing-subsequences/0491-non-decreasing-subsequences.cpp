class Solution {
public:
     void backtrack(int i,int j,vector<int>&t,set<vector<int>>& res,vector<int>& nums){
        if(nums[j]>=nums[i]){
            t.push_back(nums[j]);
            res.insert(t);
            for(int k=j+1;k<nums.size();k++){
                backtrack(j,k,t,res,nums);
            }
            t.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
         set<vector<int>> res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            vector<int> t;
            t.push_back(nums[i]);
            for(int j=i+1;j<n;j++){
                backtrack(i,j,t,res,nums);
            }
        }
        vector<vector<int>> ans(res.begin(),res.end());
        return ans;
    }
};