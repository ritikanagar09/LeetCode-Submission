class Solution {
public:
    void solve(int indx,int sum, vector<int> arr, int n, int k, vector<int>&path, set<vector<int>>&res ){

    if(indx >= n || sum > k){
        return;
    }
    if(sum==k){
        res.insert(path);
    }
        
        // cout<<indx<<endl;

    
    path.push_back(arr[indx]);
    solve(indx,sum+arr[indx],arr,n,k,path,res);
    path.pop_back();
    solve(indx+1,sum,arr,n,k,path,res);
}
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        int n=arr.size();
        set<vector<int>>st;
        vector<int>path;

        solve(0,0,arr,n,k,path,st);

        vector<vector<int>>res(st.begin(),st.end());
        return res;
    }
};