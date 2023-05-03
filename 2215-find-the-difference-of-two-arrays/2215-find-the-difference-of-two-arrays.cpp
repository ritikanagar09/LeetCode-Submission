class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans;
        vector<int>n1,n2;
        
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        
        for(int i=0;i<nums1.size();i++){
            mp1[nums1[i]]++;
        }
        
        for(int i=0;i<nums2.size();i++){
            mp2[nums2[i]]++;
        }
        
        
        for(auto el:mp1){
            if(mp2.find(el.first)==mp2.end()){
                n1.push_back(el.first);
            }
        }
        
        for(auto el:mp2){
            if(mp1.find(el.first)==mp1.end()){
                n2.push_back(el.first);
            }
        }
        
        ans.push_back(n1);
        ans.push_back(n2);
        
        return ans;
        
    }
};