class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        int maxi =0;
        for(int i =0; i<n ; i++){
            mp[nums[i]]++;
            maxi = max( maxi , mp[nums[i]]);
        }
        vector<vector<int>> ans(maxi);
        int a =0;
        for(auto i : mp){
            int k = i.second;
            //cout<<k<<" "<<i.first<<endl;
            for(int j =0; j<k ; j++){
                ans[j].push_back(i.first);
            }
        }
        return ans;
    }
};