class Solution {
public:
    
    
    void solve(int indx, string s, map<string,int>mpp,vector<string>& temp, vector<string>&ans){
        if(indx>=s.size()){
            string str="";
            for(int i=0;i<temp.size()-1;i++){
                str+=temp[i];
                str+=" ";
            }
            
            str+=temp[temp.size()-1];
            ans.push_back(str);
            
            return;
        }
        
        for(int i=indx;i<s.size();i++){
            string str=s.substr(indx,i-indx+1);
            if(mpp.find(str)!=mpp.end()){
                temp.push_back(str);
                // temp+=" ";
                solve(i+1,s,mpp,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string,int>mpp;
        int n=wordDict.size();
        for(auto str:wordDict){
            mpp[str]=1;
        }
        vector<string>ans;
        vector<string>temp;
        // string temp="";
        solve(0,s,mpp,temp,ans);
        
        
        return ans;
    }
};