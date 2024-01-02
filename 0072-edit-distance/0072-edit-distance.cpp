class Solution {
public:
    
    int solve(int i, int j, string s1, string s2,vector<vector<int>>&dp){
        
        
        // cout<<i <<" "<<j<<endl;
        if(i < 0 && j < 0){
            return 0;
        }
        
        
        if(i < 0 && j >= 0){ // first empty 
            return j+1;
        }
        
        if(j < 0 && i >= 0){
            return i+1;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s1[i]==s2[j]){
            return dp[i][j]=solve(i-1,j-1,s1,s2,dp);
        }else{
            return dp[i][j]=min(1+solve(i-1,j-1,s1,s2,dp), min(1+solve(i-1,j,s1,s2,dp), 1+solve(i,j-1,s1,s2,dp)));
        }
    }
    int minDistance(string word1, string word2) {
        
        if(word1==word2){
            return 0;
        }
        int m=word1.size();
        int n=word2.size();
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1, word1,word2,dp);
    }
};