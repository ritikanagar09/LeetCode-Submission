class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        map<int,int>mpp1;
        map<int,int>mpp2;
        
        for(int i=0;i<s.size();i++){
            mpp1[s[i]]++;
        }
        
        for(int i=0;i<t.size();i++){
            mpp2[t[i]]++;
        }
        
        for(int i=0;i<s.size();i++){
            
            if(mpp1[s[i]] != mpp2[s[i]]){
                return false;
            }
        }
        
        return true;
    }
};