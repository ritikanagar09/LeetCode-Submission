class Solution {
public:
    int solve(int indx, int walls ,vector<int>& cost, vector<int>& time, vector<vector<int>>&dp ){
        
        
        if(walls <= 0 ){
            return 0;
        }
        
        if(indx >= cost.size()){
            return 1e9;
        }
        
        if(dp[indx][walls] !=-1){
            return dp[indx][walls];
        }
        
        
        int nottake= solve(indx+1,walls ,cost,time,dp);
        int take=cost[indx]+solve(indx+1,walls-time[indx]-1,cost,time,dp);
        return dp[indx][walls]=min(nottake,take);
        
        
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        vector<vector<int>>dp(501,vector<int>(501,-1));
        return solve(0,cost.size(),cost,time, dp);
    }
};