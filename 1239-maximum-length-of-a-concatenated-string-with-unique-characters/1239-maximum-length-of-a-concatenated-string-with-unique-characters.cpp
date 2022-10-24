class Solution {
public:
    int maxi=0;
    bool check(string &s1, string &s2){
        string s= s1+s2;
        map<char, int>m;
        
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
            if(m[s[i]]>1){
                return false;
            }
        }
        
        return true;
    }
    int solve(int i , string s, vector<string>&arr, unordered_map<string, int>&mp){
        
        
        if(i>=arr.size()){
            
            int size= s.size();
            if(maxi<size){
                maxi=size;
            }
            return maxi;
            
        }
        
        
        if(mp.find(s) != mp.end()) return mp[s];
        
        int notTake= solve(i+1,s, arr, mp);
        
        int take=-1;
        if(check(s,arr[i])){
            take=solve(i+1, s+arr[i],arr,mp);
        }
        
        return max(take, notTake);
    }
    
    
    int maxLength(vector<string>& arr) {
        string s="";
        
        //vector<int>dp( arr.size()+1,-1);
        unordered_map<string, int>mp;
        return solve(0, s, arr,mp);
        
        
    }
};