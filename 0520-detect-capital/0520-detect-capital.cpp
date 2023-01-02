class Solution {
public:
    bool f3(string word){
        //lower uppercase
        int cnt=0;
        for(int i=1;i<word.length();i++){
            char ch=word[i];
            if(isupper(ch))cnt++;
            // if(i!=0){
            //     if(isupper(ch)){
            //         return false;
            //     }
            // }
            
        }
        if(cnt==0 && islower(word[0])){
            return true;
        }else if(cnt==word.length()-1){
            if(islower(word[0])){
                return false;
            }
            
        }else {
            if(cnt!=0){
                return false;
            }
        }
        
        return true;
    }
    
    bool detectCapitalUse(string word) {
        
        int n=word.length();

        return (f3(word) );
    }
};