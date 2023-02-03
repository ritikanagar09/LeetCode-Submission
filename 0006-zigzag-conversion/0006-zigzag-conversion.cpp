class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows==1){
            return s;
        }
        vector<string>ans(numRows,"");
        int dir=1;
        int line=0;
        
        int i=0;
        while(i<n){
            
            if(line==0 && dir==-1){
                dir=1;
            }
            
            if(line==numRows-1 && dir==1){
                dir=-1;
            }
            
            
            ans[line]+=s[i];
            i++;
            line+=dir;
            
            
        }
        string res="";
        for(int i=0;i<numRows;i++){
            cout<<ans[i]<<" ";
            res+=ans[i];
        }
        
        return res;
    }
};