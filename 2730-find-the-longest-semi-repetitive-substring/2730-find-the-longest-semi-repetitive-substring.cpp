class Solution {
public:
    int isPos(string s){        
        int n=s.size();
        
        int cnt=0;
        for(int i=1;i<n;i++){
            
            if(s[i]==s[i-1]){
                cnt++;
            }
        }
        
        if(cnt<=1){
            return true;
        }
        
        return false;
        
        
    }
    int longestSemiRepetitiveSubstring(string s) {
        
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string str=s.substr(i,j-i+1);
                if(isPos(str)){
                    ans=max(ans,(int)str.size());
                }
            }
        }
        
        return ans;
    }
};