//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	
	    int solve(int i, int j, string s, string c, vector<vector<int>>&dp){
    
            if( i < 0 || j<0){
                return 0;
            }
            
            if(dp[i][j]!=-1){
                return dp[i][j];
            }
            
            if(s[i]==c[j] && i!=j){
                return dp[i][j]=1+solve(i-1,j-1,s,c,dp);
            }else{
                return dp[i][j]=max(solve(i-1,j,s,c,dp),solve(i,j-1,s,c,dp));
            }
	    }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    
		    
		    string s=str;
		    string c=str;
		    
		    int n=str.size();
		    
		    vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,0));
		  //  return solve(s.size()-1,s.size()-1,s,str,dp);
		  
		  
		  for(int i=1;i<=n;i++){
		      for(int j=1;j<=n;j++){
		          if(s[i-1]==c[j-1] && i!=j){
                        dp[i][j]=1+ dp[i-1][j-1];
                    }else{
                        dp[i][j]=max( dp[i-1][j], dp[i][j-1]);
                    }
		      }
		  }
		  
		  return dp[n][n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends