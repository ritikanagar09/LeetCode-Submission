class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>v(n+1,0);
        
        for(auto it:trust){
            int a=it[0];
            int b=it[1];
            v[a]=1;
        }
        
        int pot=-1;
        
        for(int i=1;i<=n;i++){
            if(v[i]==0){
                pot=i;
            }
        }
        
        int cnt=0;
        
        for(auto it:trust){
            int a=it[0];
            int b=it[1];
            
            if(b==pot){
                cnt++;
            }
            
        }
        
        if(cnt==n-1){
            return pot;
        }
        
        return -1;
    }
};