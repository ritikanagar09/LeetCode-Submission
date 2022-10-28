class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        if(n==0){
            return {{""}};
        }
        
        // if(strs.size()>1 && strs[0].size()==0 && strs[1].size()==0){
        //     return {{"",""}};
        // }
        // if(n==1 && strs[0].size()==0){
        //     return {{""}};
        // }
       
        map<string,vector<string>>m;
        vector<vector<string>>ans;
        
        for(int i=0;i<n;i++){
            string s=strs[i];
            
            sort(s.begin(),s.end());
            m[s].push_back(strs[i]);
            
        }
        
        for(auto i:m){
            vector<string>v;
            for(auto j:i.second){
               v.push_back(j);
               
            }
           
            ans.push_back(v);
        }
        
        return ans;
    }
};