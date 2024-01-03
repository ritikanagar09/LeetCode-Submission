class Solution {
public:
    
    bool solve(int indx, string s, map<string,int>&mpp, int &n, vector<int>&dp){
        if(indx >=n){
            return true;
        }
        
        if(dp[indx] != -1){
            return dp[indx];
        }
        
        for(int i=indx;i<n;i++){
            string str=s.substr(indx,i-indx+1);
            if(mpp.find(str) != mpp.end()){
                if(solve(i+1,s,mpp,n,dp)){
                    return dp[indx]=true;
                }
            }
        }
        
        return dp[indx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        map<string,int>mpp;
        
        for(int i=0;i<wordDict.size();i++){
            mpp[wordDict[i]]++;
        }
        vector<int>dp(n,-1);
        return solve(0,s,mpp,n,dp);
    }
};