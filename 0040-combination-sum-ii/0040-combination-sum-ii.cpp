class Solution {
public:
    void solve(int indx, vector<int>& candidates, int target, vector<int>&path, vector<vector<int>>&ans){
        
        if(target==0){
            ans.push_back(path);
            return;
        }
        
        for(int i=indx;i<candidates.size();i++){
            if(i!=indx && candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            path.push_back(candidates[i]);
            solve(i+1, candidates, target-candidates[i],path,ans);
            path.pop_back();
        }
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int n=candidates.size();
        vector<int>path;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        
        solve(0,candidates, target, path,ans);
        return ans;
    }
};