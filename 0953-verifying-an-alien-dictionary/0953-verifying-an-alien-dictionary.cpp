class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
//         unordered_map<char,int>mpp;
        
        
        
//         for(int i=0;i<order.length();i++){
//             mpp[order[i]]=i+1;
//         }
        
//         for(int k=0;k<words.size()-1;k++){
//             string str1=words[k];
//             string str2=words[k+1];
//             int i=0;
            
            
            
//             while(str1[i]==str2[i]){
//                 i++;
//             }
//             if(i==0 && mpp[str1[i]]<mpp[str2[i]]){
//                 return true;
//             }
//             int n=str1.size();
//             int m=str2.size();
//             cout<<i<<endl;
//             if(i==m&& str1.size()>str2.size()){
//                 return false;
//             }
            
            
//             while(i<n && i<m){
//                 if(mpp[str1[i]]>mpp[str2[i]]){
//                     cout<<str1[i]<<" "<<str2[i]<<endl;
//                     return false;
//                 }
//                 i++;
//             }
            
            
//         }
        
        
//         return true;
        
        
        vector<int>v(26,0);

        for(int i=0;i<order.size();i++)
          v[order[i]-'a']=i;

        for(int i=0;i<words.size()-1;i++)
        {
            int len1=words[i].size();
            int len2=words[i+1].size();
            int j=0;
            while(j<len1 && j<len2)
            {
                if(words[i][j]!=words[i+1][j])
                  {if(v[words[i][j]-'a']>v[words[i+1][j]-'a'])
                      return false;
                    break;
                  }
                  j++;
            }
            if(j==len2 && j<len1)
               return false;
        }

        return true;
    }
};