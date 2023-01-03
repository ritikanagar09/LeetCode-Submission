class Solution {
public:
    string getHint(string secret, string guess) {
        map<int,int>m1,m2;
        int n=secret.size();
        int bulls=0;
        for(int i=0;i<n;i++){
            int t1=secret[i]-'0';
            int t2=guess[i]-'0';
            
            m1[t1]++;
            m2[t2]++;
            if(secret[i]==guess[i]){
                bulls++;
            }
        }
        
        int cows=0;
        
        for(auto it1:m1){
            for(auto it2:m2){
                if(it1.first==it2.first){
                    cows+=min(it1.second,it2.second);
                }
            }
        }
        
        string x=to_string(bulls);
        string y=to_string(cows-bulls);
        
        return x+"A"+y+"B";
    }
};