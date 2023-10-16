// class Solution {
// public:
//     long long int mod=1e9+7;
//     long long solve(int indx,int steps, int &arrlen, vector<vector<long long>>&dp ){
        
//         if(indx < 0 || indx>=arrlen || steps < 0){
//             return 0;
//         }
        
//         if(indx==0 && steps==0){
//             return 1;
//         }
        
//         // if(dp[indx][steps]!=-1){
//         //     return dp[indx][steps];
//         // }
        
//         if(dp[steps][indx]!=-1){
//             return dp[steps][indx];
//         }
        
//         // cout<<indx<<" "<<steps<<" "<<arrlen<<endl; 
//         int a=solve(indx,steps-1,arrlen,dp);
//         int b=solve(indx+1,steps-1,arrlen,dp);
//         int c=solve(indx-1, steps-1,arrlen,dp);
        
//         return dp[steps][indx]=(long long)(a%mod+b%mod+c%mod)%mod;
//     }
//     int numWays(int steps, int arrLen) {
        
//         vector<vector<long long>>dp(steps+1, vector<long long>(steps/2+1,-1));
//         return solve(0,steps,arrLen,dp);
//     }
// };


class Solution {
private:
    long long solve(int steps,int arrLen, int i, vector<vector<long long>> &dp){
        if(!i && !steps)
            return 1;
        if(i == arrLen || steps < 0 || i < 0 || i > steps)
            return 0;
        if(dp[steps][i] != -1)
            return dp[steps][i];
            
        long long left = solve(steps - 1, arrLen, i - 1, dp);
        long long right = solve(steps - 1, arrLen, i + 1, dp);
        long long stay = solve(steps - 1, arrLen, i, dp);
        return dp[steps][i] = (long long)((left + right + stay) % mod);
    }
public:
    long long mod = 1e9 + 7;
    int numWays(int steps, int arrLen) {
        vector<vector<long long>> dp(steps + 1, vector<long long> (steps/2 + 1, -1));
        return (int)solve(steps, arrLen, 0, dp);
    }
};