class Solution {
public:
    
    bool check(char ch)
    {
        return ch == 'a'|| ch == 'e'|| ch == 'i'|| ch == 'o'|| ch == 'u';
    }
    
    
    int maxVowels(string s, int k) {
        int n=s.length();
        int l=0;
        int r=0;
        
        int cnt=0;
        int maxcnt=0;
        
        while(r-l<k){
            
            if(check(s[r])){
                // cout<<s[r]<<endl;
                cnt++;
            }
            
            r++;
        }
        
        maxcnt=max(cnt,maxcnt);
        
        
        while(r<n){
            if(check(s[l])){
                cnt--;
            }
            
            if(check(s[r])){
                cnt++;
            }
            
            l++;
            r++;
            
            maxcnt=max(cnt,maxcnt);
            
        }
        
        return maxcnt;
    }
};