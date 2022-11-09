class Solution {
public:
    string makeGood(string s) {
        
        if(s.size()==1){
            return s;
        }
        
        
        for(int j=0;j<s.size();j++){
            int diff=abs(s[j+1]-s[j]);
            
            if(diff==32){
                s.erase(j,2);
                j=-1;
            }
        }
        
        return s;
    }
};