class Solution {
public:
    void solve(int indx, int n ,int k, vector<int>&path, vector<vector<int>>&ans, int t){
    
        
        if(n==0 && path.size()==t ){
            ans.push_back(path);
            return;
        }
        
        if(n<0 || k<0 || indx>9){
            return ;
        }
        
        path.push_back(indx);
        solve(indx+1, n-indx, k-1, path, ans,t);
        path.pop_back();
        solve(indx+1, n, k, path, ans,t);
     
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>ans;
        vector<int>path;
        solve(1,n,k,path,ans,k);
        return ans;
    }
};