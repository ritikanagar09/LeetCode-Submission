class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string>mpp;
        
        int n=s.length();
        vector<string>vec;
        string str="";
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                str+=s[i];
            }else{
                vec.push_back(str);
                str="";
            }
        }
        vec.push_back(str);
        // for(auto i:vec){
        //     cout<<i<<endl;
        // }
        int m=pattern.size();
        int v=vec.size();
        
        if(m!=v){
            return false;
        }
        
        for(int i=0;i<pattern.length();i++){
            char a =pattern[i];
            if(mpp.find(a)==mpp.end()){
                mpp[a]=vec[i];
            }
            
            // if(mpp.find(a)!=mpp.end()){
            //     if(mpp[a]==vec[i]){
            //         return false;
            //     }
            // }
            
            
            if(mpp[a]!=vec[i]){
                return false;
            }else{
                string ch=mpp[a];
                for(auto it:mpp){
                    if(it.first!=a && it.second==vec[i]){
                        return false;
                    }else if(it.first!=a && it.second==ch){
                        return false;
                    }
                }
            }
           
        }
        
        return true;
        
    }
};