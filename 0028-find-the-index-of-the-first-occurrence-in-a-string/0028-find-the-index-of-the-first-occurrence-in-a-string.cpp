class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int s=needle.size();
        if(n<s){
            return -1;
        }
        for(int i=0;i<n;i++){
            
            if(haystack[i]==needle[0]){
                bool flag=true;
                for(int j=1;j<s;j++){
                    if(i+j<n && haystack[i+j]!=needle[j]){
                        //cout<<i<<" "<<j<<endl;
                        flag=false;
                    }
                }
                
                if(flag && n-i>=s ){

                    return i;
                }
            }
        }
        
        return -1;
    }
};