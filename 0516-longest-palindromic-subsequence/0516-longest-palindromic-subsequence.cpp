class Solution {
public:
    
    int lcs(string s, string t)
{
	// return solve(s.size()-1, t.size()-1, s,t);

	vector<vector<int>>dp(s.size()+1, vector<int>(t.size()+1,0));

	for(int i=1;i<=s.size();i++){
		for(int j=1;j<=t.size();j++){
			if(s[i-1]==t[j-1]){
				dp[i][j]= 1+dp[i-1][j-1];
			}else{
				dp[i][j]= 0+max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	return dp[s.size()][t.size()];

}
    int LCS(string &s1, string &s2){
        
        int n=s1.size();
        int m=s2.size();
        
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
        
    }
    int longestPalindromeSubseq(string s) {
        
        string s1=s;
        reverse(s.begin(),s.end());
        return lcs(s1,s);
        
    }
};