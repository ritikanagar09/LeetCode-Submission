class Solution {
public:
    string customSortString(string order, string s) {
        int n=order.size();
        int m=s.size();
        
        map<char,int>mapp;
        
        for(int i=0;i<n;i++){
            mapp[order[i]]=i;
        }
        
        vector<pair<int,char>>v;
        
        for(int i=0;i<m;i++){
            char ch=s[i];
            int val=mapp[s[i]];
            
            v.push_back({val,ch});
        }
        
        sort(v.begin(),v.end());
        
        string ans;
        for(auto it:v){
            pair p = it;
            ans+=p.second;
        }
        
        return ans;
        
        
    }
};