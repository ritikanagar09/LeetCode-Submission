class Solution {
public:
    
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||ch=='A' ||ch=='E' ||ch=='I' || ch=='O' || ch=='U' ){
            return true;
        }
        
        return false;
    }
    string sortVowels(string s) {
        int n=s.size();
        vector<char>v;
        for(int i=0;i<n;i++ ){
            if(isVowel(s[i])){
                v.push_back(s[i]);
            }
        }
        
        sort(v.begin(),v.end());
        int cnt=0;
        for(int i=0;i<n;i++ ){
            if(isVowel(s[i])){
                s[i]=v[cnt];
                cnt++;
            }
        }
        
        
        

        
        return s;
    }
};