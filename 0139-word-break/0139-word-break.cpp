class Solution {
public:
    
    bool solve(int indx, string s, map<string,int>mpp,vector<int>&dp){
        
        if(indx >=s.size()){
            return true;
        }
        
        if(dp[indx]!=-1){
            return dp[indx];
        }
        for(int i=indx;i<s.size();i++){
            string str=s.substr(indx,i-indx+1);
            if(mpp.find(str)!=mpp.end()){
                if(solve(i+1,s,mpp,dp)){
                    return dp[i]=true;
                }
            }
        }
        
        return dp[indx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,int>mpp;
        int n=wordDict.size();
        for(auto str:wordDict){
            mpp[str]=1;
        }
        vector<int>dp(301,-1);
        return solve(0,s,mpp,dp);
    }
};