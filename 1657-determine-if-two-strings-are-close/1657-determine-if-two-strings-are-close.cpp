class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        if(n1!=n2){
            return false;
        }
    
        
        //ab dimaag lagate hai 
        //ab monika ko ye yaad rahga questions 
        //ush mohit bheju tereko ..
        //uska kitna tagda hai 
        //kya??
        //resume
        
        //
        
        // aabbbc   abbccc
        // a=3      a=1
        // b=2      b=2
        // c=1      c=3
        
        set<char>s1,s2;
        vector<int>f1(26,0),f2(26,0);
        
        for(int i=0;i<n1;i++){
            s1.insert(word1[i]);
            s2.insert(word2[i]);
            f1[word1[i]-'a']++;
            f2[word2[i]-'a']++;
            
        }
        
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        if(s1==s2 && f1==f2){
            return true;
        }
        
        return false;
        
    }
};