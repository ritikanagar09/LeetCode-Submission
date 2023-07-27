class Solution {
public:
    
    
    void solve(int indx, vector<int>&nums, vector<int>&path, vector<vector<int>>&res, int n){
        
        // cout<<indx<<endl;
        if(indx >= n-1){
            // cout<<"&&"<<endl;
            // cout<<indx<<" "<<nums.size()<<endl;
            res.push_back(path);
            return;
        }
        
        
        
        for(int i=0;i<nums.size();i++){
            
            // cout<<"///"<<endl;
            if(find(path.begin(), path.end(), nums[i])!=path.end())continue;
            // cout<<"^^^"<<endl;
            path.push_back(nums[i]);
            solve(indx+1,nums,path,res,n);
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        vector<int>path;
        solve(-1,nums,path,res,n);
        // cout<<"///"<<endl;
        return res;
        
    }
};