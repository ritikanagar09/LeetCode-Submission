class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int cnt=0;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<s.size();j++){
                if(s[j] >= g[i]){
                    s[j]=0;
                    cnt++;
                    break;
                }
            }
        }
        
        return cnt;
    }
};