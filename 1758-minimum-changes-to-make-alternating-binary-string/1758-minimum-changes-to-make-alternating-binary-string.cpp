class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        
        char first=s[0];
        
        int cnt=0;
        // if we strating from 1 
        // then at even pos--1
        // odd pos--> 0
        // this is rule 
        
        for(int i=0;i<n;i++){
            if(i%2==0 && s[i]!='1'){
                cnt++;
            }
            
            if(i%2 !=0 && s[i]!='0'){
                cnt++;
            }
        }
        
        int cnt1=0;
        for(int i=0;i<n;i++){
            if(i%2==0 && s[i]!='0'){
                cnt1++;
            }
            
            if(i%2 !=0 && s[i]!='1'){
                cnt1++;
            }
        }
        
         return min(cnt,cnt1);
        
    }
};