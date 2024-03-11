class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        map<int,int>mapp;
        
        for(auto it:nums1){
            mapp[it]=1;
        }
        
        set<int>st;
        
        for(int i=0;i<m;i++){
            if(mapp.find(nums2[i]) !=mapp.end()){
                st.insert(nums2[i]);
            }
        }
        
        vector<int>v(st.begin(),st.end());
        return v;
    }
};