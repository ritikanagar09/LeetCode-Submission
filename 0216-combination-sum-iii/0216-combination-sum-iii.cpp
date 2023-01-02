class Solution {
public:
    void solve(int indx, int n ,int k, vector<int>&path, vector<vector<int>>&ans, int t){
    
        
        if(n==0 && path.size()==t ){
            cout<<"///"<<endl;
            ans.push_back(path);
            return;
        }
        
        if(n<0 || k<0){
            return ;
        }
        
       // cout<<n<<" "<<k<<endl;
        
        for(int j=indx;j<=9;j++){
            path.push_back(j);
            solve(j+1, n-j,k-1,path,ans,t);
            path.pop_back();
        }
     
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>ans;
        vector<int>path;
        solve(1,n,k,path,ans,k);
        return ans;
    }
};