class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        int n=words.size();
        unordered_set<string>st;
        
        for(auto w: words){
            
            string odd, even;
            for(int i=0;i<w.size();i++){
                
                if(i%2==0){
                    even+=w[i];
                }else{
                    odd+=w[i];
                }
            }
            
            sort(odd.begin(),odd.end());
            sort(even.begin(),even.end());
            string ans=odd+even;
            st.insert(ans);
        }
        
        return st.size();
        
    }
};