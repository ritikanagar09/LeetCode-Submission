class Solution {
public:
   
    string gcdOfStrings(string str1, string str2) {
        
        
        int n=str1.size();
        int m=str2.size();
        if(str1+str2!=str2+str1){
            return "";
        }
        int g=gcd(n,m);
        cout<<g<<endl;
        string ans="";
        for(int i=0;i<g;i++){
            ans+=str1[i];
        }
        
        return ans;
    }
};