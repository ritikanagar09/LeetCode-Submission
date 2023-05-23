class Solution {
public:
    
    // bool checkpali(int l, int r, string&s){
    //     while(l<=r){
    //         if(s[l++]!=s[r--]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    
    bool checkpali(int start, int end, string s){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
            
            }
        return true;
    }
    void solve(int indx, string s, vector<vector<string>>&ans,vector<string>&path){
        if(indx==s.size()){
            ans.push_back(path);
            return;
        }
        
        
        //asli kaam 
        
        for(int i=indx;i<s.size();i++){
            if(checkpali(indx,i,s)){
                path.push_back(s.substr(indx, i-indx+1));
                solve(i+1,s,ans,path);
                path.pop_back();
            }
        }
    }
               
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        
        
        solve(0,s,ans,path);
        
        return ans;
    }
};