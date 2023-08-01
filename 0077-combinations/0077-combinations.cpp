class Solution {
public:
    
    void solve(int indx, int k,vector<int>&path, vector<vector<int>>&ans,int n ){
        if(k==0){
            ans.push_back(path);
            return;
        }
        
        if(indx > n){
            return;
        }
        // cout<<"//"<<endl;
        
        
        path.push_back(indx);
        solve(indx+1,k-1,path,ans,n);
        path.pop_back();
        solve(indx+1,k,path,ans,n);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>path;
    
        solve(1,k,path,ans,n);
        return ans;
        
    }
};