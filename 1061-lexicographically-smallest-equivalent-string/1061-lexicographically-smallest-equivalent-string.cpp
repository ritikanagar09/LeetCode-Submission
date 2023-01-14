class Solution {
public:
    
    char dfs(char ch,unordered_map<char,vector<char>>adj,vector<int>&vis ){
       
        
        vis[ch-'a']=1;
        
        char ch1=ch;
        for(char it: adj[ch]){
            if(vis[it-'a']!=1){
                char temp=dfs(it,adj,vis);
                if(temp<ch1){
                    ch1=temp;
                }
            }
        }
        
        return ch1;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        int n=s1.length();
        int m=2*n;
        unordered_map<char , vector<char>>adj;
        
        for(int i=0;i<n;i++){
            char u=s1[i];
            char v=s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        string ans;
        
        for(int i=0;i<baseStr.size();i++){
            
            char ch=baseStr[i];
            vector<int>vis(26,0);
            
            char min=dfs(ch,adj,vis);
            ans+=min;
        }
        return ans;
    }
};