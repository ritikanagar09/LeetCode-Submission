class Solution {
public:
    int solve(int i, int j , string s1,string s2){
        
        // base 
        
        if(i<0){
            return j+1;
        }
        
        if(j<0){
            return i+1;
        }
        
        
        
        //matching 
        if(s1[i]==s2[j]){
            return solve(i-1,j-1,s1,s2);
        }else{
            
            // int a=1+solve(i-1,j,s1,s2);
            // int a=1+solve(i-1,j,s1,s2);
            // int a=1+solve(i-1,j,s1,s2);
            
            return 1+min(solve(i-1,j,s1,s2), min(solve(i,j-1,s1,s2),solve(i-1,j-1,s1,s2)));
        }
        
        // ye alag tareeka h return krne kaa ..
//         becuase at the end hume apni recursion call me se koi ek cheez toh return krni hai 
        
    }
    int minDistance(string word1, string word2) {
        // return solve(word1.size(),word2.size(),word1,word2);
        
        
        //tabulation 
        
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1));
        
        
        for(int j=0;j<=word2.size();j++){
            dp[0][j]=j;// one based indexing h islye
        }
        
        for(int i=0;i<=word1.size();i++){
            dp[i][0]=i;
        }
        
        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] =dp[i-1][j-1];
                }else{

                    dp[i][j]=1+min(dp[i-1][j], min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        
        
        return dp[word1.size()][word2.size()];
    }
};