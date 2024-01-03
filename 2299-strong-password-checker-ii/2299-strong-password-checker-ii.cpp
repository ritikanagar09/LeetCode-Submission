class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        int n=s.size();
        if(n < 8){
            return false;
        }
        
        // lower case 91-> 122
        // upper case 65->90
        // digit 0->9 
        
        bool f1=false;
        bool f2=false;
        bool f3=false;
        bool f4=false;
        
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch >='0' && ch <='9' ){
                f1=true;
            }else if(ch >='a' && ch<='z'){
                f2=true;
            }else if(ch>='A' && ch <= 'Z'){
                f3=true;
            }else{
                f4=true;
            }
        }
        for(int i=1;i<n;i++){
            if(s[i] == s[i-1]){
                return false;
            }
        }
        
        return f1 && f2 && f3 && f4;
        
    }
};