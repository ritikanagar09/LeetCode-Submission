class Solution {
public:
    bool f1(string word){
        //lower uppercase
        
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            bool flag=(ch>=65 && ch<=90);
            if(!flag){
                return false;
            }
        }
        
        return true;
    }
    
    
     bool f2(string word){
        //all lower case
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            
            if(i!=0){
                if(isupper(ch)){
                    return false;
                }
            }
            
            
            
        }
          return true;
     }

    bool f3(string word){
        //lower uppercase
        
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(!islower(ch)){
                return false;
            }
        }
        
        return true;
    }
    
    bool detectCapitalUse(string word) {
        
        int n=word.length();

        return (f1(word) || f2(word) || f3(word) );
    }
};