class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n =arr.size();
        
        map<int,int>mpp;
        
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        
        // here the number of elemts there are 
        // we are required to have that much 
        // distinct elemnts only 
        map<int,int>mpp1;
        
        for(auto it:mpp){
            int s=it.second;
            if(mpp1.find(s)==mpp1.end()){
                mpp1[s]=1;
            }else{
                return false;
            }
        }
        
        return true;
        
        
    }
};