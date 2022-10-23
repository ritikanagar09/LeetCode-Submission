class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // abs(i - j) <= k ye inhone ek window hi toh bta di h ek type ki ..ki tumhare i and j should be present in this window only.. not outside this.
        
        
        int i=0;
        int j=0;
        
        int n=nums.size();
        map<int,vector<int>>mpp;
        
        for(int i=0 ;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        
        
        
        for(auto i:mpp){
            
            vector<int>v=i.second;
            if(v.size()>=2){
                for(int i=0;i<v.size();i++){
                    //cout<<v[i]<<endl;
                   for(int j=i;j<v.size();j++){
                       if(i!=j && abs(v[i]-v[j])<=k){
                           
                           return true;
                           
                       }
                   }
                }
            }
            
        }
        
        return false;
        
    }
};