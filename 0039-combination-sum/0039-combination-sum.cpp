class Solution {
public:
    void solve(int i,int &sum, vector<int>& candidates, int target, vector<int>&path, vector<vector<int>>&ans, int n ){
        if(sum==target){
            ans.push_back(path);
            return;
        }
        
        if(i>=n || sum>target){
            return;
        }
        cout<<i<<" "<<sum<<endl;
        path.push_back(candidates[i]);
        sum+=candidates[i];
        solve(i,sum,candidates, target,path,ans,n);
        path.pop_back();
        sum-=candidates[i];
        solve(i+1,sum,candidates, target,path,ans,n);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n=candidates.size();
        vector<int>path;
        vector<vector<int>>ans;
        int sum=0;
        solve(0, sum, candidates, target, path ,ans,n);
        return ans;
    }
};