class Solution {
public:
    
    int longestPalindrome(vector<string>& words) {
        int n=words.size();

        map<string,int>mp;

        for(auto i:words){
            mp[i]++;
        }
        
        int ans=0;
        bool flag=false;
        for(auto i:mp){
            
            string x=i.first;
            string t=x;
            reverse(t.begin(),t.end());
            
            if(t==x){
                ans+=i.second/2;
                if(i.second%2==1){
                    flag=true;
                }
            }else{
                
                ans+=min(i.second,mp[t]);
                mp.erase(t);
            }
        }
        
        ans=ans*4;
        if(flag){
            ans+=2;
        }
        
        return ans;
        
        
        
    }
};