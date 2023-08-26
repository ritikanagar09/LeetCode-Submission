class Solution {
public:
    int solve(int prev, int curr, vector<vector<int>>& pairs,vector<vector<int>>&dp ){
        
        if(curr==pairs.size()){
            return 0;
        }
        
        if(dp[prev+1][curr]!=-1){
            return dp[prev+1][curr];
        }
        
        int nottake=solve(prev,curr+1,pairs,dp);
        
        int take=INT_MIN;
        if(prev ==-1 || pairs[curr][0] > pairs[prev][1]){ // prev==-1 indeictaes if there is not previous lement and then you need to include the first elemnt that is present in the array 
            take=1+solve(curr,curr+1,pairs,dp);
        }
        
        return dp[prev+1][curr]=max(nottake,take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(-1,0,pairs,dp );
    }
};