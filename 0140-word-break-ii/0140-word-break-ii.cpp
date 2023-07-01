class Solution {
public:
    
    void solve(int indx, string s,set<string>& dict, vector<string>&path, vector<string>&ans){
        
        if(indx==s.size()){
            string temp="";
            for(int j=0;j<path.size()-1;j++){
                temp+=path[j];
                temp+=" ";
            }
            
            temp+=path[path.size()-1];
            ans.push_back(temp);
            return;
        }
        
        
        for(int i=indx;i<s.size();i++){
            string sub=s.substr(indx, i-indx+1);
            
            if(dict.find(sub)!=dict.end()){
                // sub+=" ";
                path.push_back(sub);
                solve(i+1,s,dict,path,ans);
                path.pop_back();
            }
            
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>path;
        vector<string>ans;
        
        set<string>st;
        
        for(auto it:wordDict){
            st.insert(it);
        }
        solve(0,s,st,path,ans);
        
        return ans;
    }
};