class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n=paths.size();
        
        map<string,int>mppA;
        // map<string,int>mppD;
        
        for(int i=0;i<n;i++){
            string a=paths[i][0]; 
            string b=paths[i][1];
            mppA[a]++;
            
           
        }
        
        
        for(int i=0 ;i<n;i++){
            string b=paths[i][1];
            if(mppA[b]==0){
                return b;
            }
            
        }
        
        return " ";
        
        
       
    }
};