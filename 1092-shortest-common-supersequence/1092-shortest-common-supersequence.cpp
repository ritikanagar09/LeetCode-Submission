class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int m=s.size();
        int n=t.size();

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


        int i=m;
        int j=n;

        string str="";

        int len=dp[m][n];

        while(i>0 && j>0){

            if(s[i-1]==t[j-1]){
                str+=s[i-1];

                i--;
                j--;
            }else if(dp[i-1][j]>dp[i][j-1]){
                str+=s[i-1];
                i--;
            }else{
                str+=t[j-1];
                j--;
            }


        }

        while(i>0){
            str+=s[i-1];
            i--;
        }

        while(j>0){
            str+=t[j-1];
            j--;
        }
        
        reverse(str.begin(),str.end());

            return str;
    }
};