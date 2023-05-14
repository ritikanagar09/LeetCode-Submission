class Solution {
public:
    int l,h, z, o;
    int mod=1e9+7;
    int solve(int len,vector<int>&dp ){
        if(len>h){
            return 0;
        }
        
//         cout<<str.length()<<endl;
//         cout<<dp[str.length()]<<endl;
        if(dp[len]!=-1){
            
            return dp[len];
        }
        int ans=0;
        
        if(len>=l){
            ans=1;
        }
        
        
        int len1=len+z;
        int len2=len+o;
        
        
        int a=solve(len1,dp);
        
        
        int r=solve(len2,dp);
        
        
        
        // return dp[str.length()]=ans+a+r;
        return dp[len]=(ans+a+r)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        l=low;
        h=high;
        z=zero;
        o=one;
        
        vector<int>dp(high+1,-1);
        return solve(0,dp);
        
        // return solve(0,"");
    }
};