class Solution {
public:
    string breakPalindrome(string palindrome) {
        string p=palindrome;
        int n=palindrome.length();
        int l=0;
        int r=n-1;
        if(n<=1){
            return "";
        }
        
        
        while(l<r){
            if(palindrome[l]!='a' && palindrome[r]!='a'){
                palindrome[l]='a';
                return palindrome;
            }else{
                l++;
                r--;
            }
        }
        
        palindrome[n-1]='b';
        
        return palindrome;
    }
};