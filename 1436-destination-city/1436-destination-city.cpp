class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n=paths.size();
        
        map<string,int>mppA;
        map<string,int>mppD;
        
        for(int i=0;i<n;i++){
            string a=paths[i][0]; 
            string b=paths[i][1];
            mppA[a]++;
            mppD[b]++;
        }
        
        
        string ans;
        for(auto it:mppD){
            if(mppA.find(it.first)==mppA.end()){
                return it.first;
            }
        }
        
        return ans;
    }
};