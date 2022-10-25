class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string s1="";
        string s2="";
        
        
        for(int i=0;i<word1.size();i++){
            string s= word1[i];
            s1+=s;
        }
        
        for(int i=0;i<word2.size();i++){
            string s= word2[i];
            s2+=s;
        }
        
        if(s1==s2){
            return true;
        }
        
        return false;
    }
};