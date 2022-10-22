class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>m, mf;
        ///
        for(int i =0; i<t.size(); i++){
            m[t[i]]++;
        }
        ///
        int n = s.size();
        int i =0 ;
        int j =0;
        int maxi = INT_MAX;
        string ans ="";

        while(i<n){
            bool x = true;
            if(j<n){
            mf[s[j]]++;
            }
            // check 
            for(auto i : m){
                char h = i.first;
                if(m[h]>mf[h]){
                    x = false;
                    break;
                }
            }
//  BCAB MF  // ABC M  
            while( x == true && i<n){
             if((j-i+1)<maxi){
                 maxi = j-i+1;
                 ans = s.substr(i,j-i+1);
             }
                mf[s[i]]--;
                i++;
                
           for(auto i : m){
                char h = i.first;
                if(m[h]>mf[h]){
                    x = false;
                    break;
                }
            }
            }
            if(j<n ){
                j++;
            }
            else{
               mf[s[i]]--;
                i++;
            }
        }
        return ans;
    }
};