class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        if(x==0){
            return 0;
        }
        
        int n=nums.size();
        
        int ans=1e9;
        
        set<int>st;
        
        for(int i=x;i<n;i++){
            st.insert(nums[i-x]);
            auto indx=st.lower_bound(nums[i]);
            
            if(indx != st.end()){
                ans=min(ans, abs(*indx - nums[i])); // smallest elem just graeter than nums[i];
            }
            
            if(indx != st.begin()){
                indx--;
                ans=min(ans, abs(*indx - nums[i])); // *indx -> itertor pointing to that element
            }
        }
        
        return ans;
    }
};