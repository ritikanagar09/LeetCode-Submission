class Solution {
public:
    string orderlyQueue(string str, int k) {
        string prev="cba";
        string ans="{";
        int n=str.length();
        
        
        // saare character k sath kr le ye 
        // bcoz agar k is 1 ..then we have to send all the initial characters to end
        string s= str;
        if(k==1){
            while(n--){
                char ch=s[0];
                s=s.substr(1);
                
                s+=ch;
                if(s<ans){
                    ans=s;
                }
            }
            
            return ans;
        }
        
        sort(str.begin(),str.end());
        return str;
        
    }
};