class Solution {
public:
    
    bool static comp(pair<int,int>p1,pair<int,int>p2){
        if(p1.second>p2.second){
            return true;
        }else if(p1.second==p2.second){
            return p1.first<p2.first;
        }
        
        return false;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto i:nums){
            mpp[i]++;
        }
        
        vector<pair<int,int>>v;
        for(auto i:mpp){
            v.push_back({i.first,i.second});
            
        }
        
        sort(v.begin(),v.end(),comp);
        
        
        vector<int>ans;
        
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        
        
        return ans;
        
       
    }
};