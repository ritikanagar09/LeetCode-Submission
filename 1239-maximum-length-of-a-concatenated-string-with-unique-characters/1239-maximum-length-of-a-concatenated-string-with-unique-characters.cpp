class Solution {
public:
    
    int solve(int indx, vector<string>&arr, string str){
        if(indx >=arr.size()){
            return 0;
        }
        
        
        map<char,int>mpp;
        bool flag1=true;
        string curr=arr[indx];
        string newstr=str+curr;
        for(auto ch:newstr){
            mpp[ch]++;
            
        }
        
        bool flag=true;
        
        for(auto it:mpp){
            if(it.second > 1){
                flag=false;
            }
        }
        
        int take=0;
        if(flag && flag1){
            take=curr.size() +solve(indx+1,arr, str+curr);
        }
        
        int nottake=solve(indx+1,arr,str);
        
        return max(take,nottake);
        
        
    }
    int maxLength(vector<string>& arr) {
        
        string str="";
        return solve(0,arr,str);
    }
};