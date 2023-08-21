class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len=s.size();
        string nextstr=s;
        for(int i=1;i<=len/2;i++){
            if(len%i==0){
                
                nextstr=left(s,i);
                if(nextstr==s){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    string left(string &s,int i){
        string ret=s.substr(i);
        
        // cout<<ret<<endl;
        ret+=s.substr(0,i);
        return ret;
    }
};