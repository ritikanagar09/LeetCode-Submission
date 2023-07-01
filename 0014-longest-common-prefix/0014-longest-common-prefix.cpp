class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        
        string str="";
        
        bool flag=true;
        int n=strs.size();
        for(int i=0;i<strs[0].size();i++){
            char ch=strs[0][i];
            
            for(int j=1;j<n;j++){
                
                cout<<i<<"//"<<endl;
                if(i>=strs[j].size()){
            
                    flag=false;
                    break;
                }
                    char ch1=strs[j][i];
                
                    if(ch!=ch1){
                        flag=false;
                    }
            }
            
            cout<<i<<endl;
            
            if(flag){
                str+=ch;
            }
        }
        
        return str;
    }
};