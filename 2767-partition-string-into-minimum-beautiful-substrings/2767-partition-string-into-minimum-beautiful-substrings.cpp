class Solution {
public:
    
    bool isValid(string str){
        if(str[0]=='0'){
            return false;
        }
        
        int k=1;
        int res=0;
        for(int i=str.size()-1;i>=0;i--){
            
            res+=(str[i]-'0')*k;
            
            k=k*2;
        }
        
        while(res>1){
            if(res%5==0) res=res/5;
            else return 0;
        }
        return 1;
    }
    int solve(int indx, string s, int n){
        
        
        if(indx>=n){
            // mini=min(mini,cnt);
            return 0;
        }
        
        int mini=1e9;
        for(int i=indx;i<n;i++){
            string str=s.substr(indx,i-indx+1);
            if(isValid(str)){
                // cnt++;
                int ans=1+solve(i+1,s,n);
                
                mini=min(mini,ans );
                
            }
        }
        
        return mini;
    }
    int minimumBeautifulSubstrings(string s) {
        
        int cnt=0;
        int mini=INT_MAX;
        int ans= solve(0,s,s.size());
        
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};