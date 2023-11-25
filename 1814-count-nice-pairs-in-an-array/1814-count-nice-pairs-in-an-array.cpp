class Solution {
public:
    long long int mod=1e9+7;
    // int rev(int n){
    //     string s=to_string(n);
    //     reverse(s.begin(),s.end());
    //     int k=stol(s);
    //     return k;
    // }
     int rev(int x) {
        int result = 0;
        while (x > 0) {
            result = 10 * result + (x % 10);
            x /= 10;
        }
        return result;
    }
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            int k=rev(nums[i]);
            int val=nums[i]-k;
            mpp[val]++;
        }
        
        long long int ans=0;
        for(auto it:mpp){
            if(it.second > 1){
                int value=it.second;
                long long pairs = ((1LL * value * (value - 1)) / 2LL) % mod;
                ans= (ans + pairs) %mod;
            }
        }
        return ans;
        
    }
};