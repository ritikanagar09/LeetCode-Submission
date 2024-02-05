class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        
        vector<int>v(26,0);
        
        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
        }
        
        int indx=-1;
        
        for(int i=0;i<n;i++){
            if(v[s[i]-'a']==1){
                indx=i;
                break;
            }
        }
        
        return indx;
        
    }
};