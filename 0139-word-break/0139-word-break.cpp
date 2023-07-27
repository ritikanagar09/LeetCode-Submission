class Solution {
public:
    int dp[301];
    bool solve(int indx, string s, map<string,int>& dict ){
        
        if(indx>=s.size()){
            return true;
        }
        
        if(dp[indx]!=-1){
            return dp[indx];
        }
        
        for(int i=indx;i<s.size();i++){
            string sub=s.substr(indx,i-indx+1);
            
            if(dict.find(sub)!=dict.end()){
                // return solve(i+1,s,dict); 
                
                if(solve(i+1,s,dict)){
                    return dp[i]=1; // this line is ensuirng ki agar true ata h toh ..tabhi rteurn true krna 
                    // this means -> if false ata h toh return nothing and try exploring aage k paths 
                    // they might give us true
                    // but agar pehle hi false krva doge toh ..how woll try other ways also 
                }
                    
                
            }
        }
        
        
        return dp[indx]=false;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        map<string,int>mpp;
        memset(dp,-1,sizeof dp);
        
        for(auto str:wordDict){
            // st.insert(str);
            mpp[str]=1;
        }
        
        
        return solve(0,s,mpp);
    }
};