class Solution {
public:
    
//     bool solve1(int i, int j, string p, string s){
        
//         if(i<0 || j <0){
//             return true;
//         }
        
//         if(i<0 || j>=0){
//             return false;
//         }
        
//         if(i>=0 || j<0){// matlab string khtm hi gyi hai..par pattern bach rha hai ..now this can be match only when that pattern is all stars * 
            
//             for(int k=0;i<=i;k++){
//                 if(p[k] !='*'){
//                     return false;
//                 }
//             }
            
            
//             return true;
            
//         }
        
//         // matlab naa hi vo question mark tha..naa hi * ..na hi character match ho paa rhe the 
//         if(p[i]==s[j] || p[i]=='?'){
//             return solve1(i-1,j-1,s,p);
//         }
//         else if(p[i]=='*'){
//             return (solve1(i,j-1,s,p)||solve1(i-1,j,s,p));
            
//         } 
        
//         else return false;
    
    
//     }
    
    
    bool solve(string &str, string &pat, int i, int j,vector<vector<int>>&dp){
        // base case
        // both str and pattern are consumed
        if(i<0 and j<0) return true;
        // if str is not consumed completely and pattern is consumed acopletely
        if(i>=0 and j<0) return false;
        // my string is consumed but my pattern is not consumed
        if(i<0 and j>=0){
            // there are two cases here 
            // 1 st is if we dont find anything except * then return false
            // otherwise when we find * return true

            for(int k=0;k<=j;k++){
                if(pat[k] != '*'){
                    return false;
                }
            }
            return true;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // if match
        if(str[i] == pat[j] || pat[j] == '?'){
            return dp[i][j]=solve(str,pat,i-1,j-1,dp);
        }
        else if(pat[j] == '*'){
            return dp[i][j]=(solve(str,pat,i-1,j,dp) || solve(str,pat,i,j-1,dp));
        }
        else return dp[i][j]=false;

    }

    bool isMatch(string s, string p) {
        
        vector<vector<int>>dp(s.length()+1, vector<int>(p.length(),-1));
        // return solve(p.size()-1, s.size()-1,p,s);
       return solve(s, p, s.length()-1, p.length()-1,dp);
    }
};