class Solution {
public:
    bool isValid(string s){
        if(s[0]=='0' && s.size() > 1){
            return false;
        }
        int k=stoi(s);
        
        if(k >=1 && k<=26){
            return true;
        }
        
        return false;
    }
    int solve(int indx, string s, vector<int>&dp){
        
        if(indx >= s.size()){
            return 1;
        }
        
        
        if(dp[indx] != -1){
            return dp[indx];
        }
        int cnt=0;
        string str;
        str+=s[indx];
        
        if(isValid(str)){
            cnt+=solve(indx+1,s,dp);
        }
        
        if(indx + 1 < s.size()){
            str+=s[indx+1];
            if(isValid(str)){
                cnt+=solve(indx+2,s,dp);
            }
        }
        
        return dp[indx]=cnt;
        
    }
    int numDecodings(string s) {
        
        vector<int>dp(s.size(),-1);
        return solve(0,s,dp);
    }
};