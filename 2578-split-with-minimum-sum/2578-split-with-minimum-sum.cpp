class Solution {
public:
    int splitNum(int num) {
        string s=to_string(num);
        string a="";
        string b="";
        sort(s.begin(),s.end());
        for(int i=0;i<s.length();i++){
            
            if(i%2==0){
                a+=s[i];
            }else{
                b+=s[i];
            }
        }
        
        
        int k=stoi(a);
        int m=stoi(b);
        return k+m;
        
    }
};