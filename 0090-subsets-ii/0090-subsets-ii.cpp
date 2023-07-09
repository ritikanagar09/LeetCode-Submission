class Solution {
public:
    void solve(int indx,vector<int> &arr,vector<vector<int>>&st, vector<int>path ){
    if(indx < 0){
        sort(path.begin(),path.end());
        // if(st.find(path)==st.end()){
            st.push_back(path);
        // }

        return;
    }
    
    
    solve(indx-1,arr, st,path);
    path.push_back(arr[indx]);
    solve(indx-1,arr,st,path);
    // path.pop_back();
    
}
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>st;
        vector<int>path;
        solve(n-1,arr,st,path);

        set<vector<int>>myst;
        for(auto v:st){
            vector<int>temp=v;
            sort(v.begin(),v.end());
            if(myst.find(v)==myst.end()){
                myst.insert(temp);
            }
        }
        vector<vector<int>>res(myst.begin(),myst.end());



        // cout<<"s "<<res.size()<<endl;

        return res;
    }
};